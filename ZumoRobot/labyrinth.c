#include <project.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Motor.h"
#include "Ultra.h"
#include "Nunchuk.h"
#include "Reflectance.h"
#include "Gyro.h"
#include "Accel_magnet.h"
#include "LSM303D.h"
#include "IR.h"
#include "Beep.h"
#include "mqtt_sender.h"
#include <time.h>
#include <sys/time.h>
#include "serial1.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
#include <sys/time.h>
#include <stdio.h>

//AUTHOR @silsanteri @dievskiy @DXGGX

void motor_tankturn(uint8 l_driv, uint8 r_driv, uint8 l_speed, uint8 r_speed, uint16 delay)
{
    MotorDirLeft_Write(l_driv);
    MotorDirRight_Write(r_driv);
    PWM_WriteCompare1(l_speed); 
    PWM_WriteCompare2(r_speed); 
    vTaskDelay(delay);
}

#if 1
void zmain(void)
{
    Ultra_Start();
    IR_Start();
    motor_start();
    IR_flush();
    
    struct sensors_ dig;
    int loopbreak = 0, lastdir = 1, dir = 1, x = 0, y = -1, d = 0, linecount = 0;
    
    TickType_t startline;
    TickType_t endline;
    TickType_t hit;

    //DIR - 1 = FORWARD, 2 = LEFT, 3 = RIGHT
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    while(SW1_Read() == 1){
        vTaskDelay(1);
    }
    vTaskDelay(1000);
    while(true){
        reflectance_digital(&dig);
        d = Ultra_GetDistance();
        if(d <= 20 && lastdir == 3) {
            motor_tankturn(1,0,255,255,0);
            while(!(!dig.l3 && !dig.l2 && !dig.l1 && !dig.r1 && !dig.r2 && !dig.r3)){
                reflectance_digital(&dig);
                motor_tankturn(1,0,255,255,0);
            }
            while(!dig.l3 && !dig.l2 && dig.l1 && dig.r1 && !dig.r2 && !dig.r3){
                reflectance_digital(&dig);
                motor_tankturn(1,0,255,255,0);
            }
            lastdir = 0;
            loopbreak = 1;
            dir = 2;
        } else if(d <= 20 && lastdir == 2){
            motor_tankturn(0,1,255,255,0);
            while(!(!dig.l3 && !dig.l2 && !dig.l1 && !dig.r1 && !dig.r2 && !dig.r3)){
                reflectance_digital(&dig);
                motor_tankturn(0,1,255,255,0);
            }
            while(!dig.l3 && !dig.l2 && dig.l1 && dig.r1 && !dig.r2 && !dig.r3){
                reflectance_digital(&dig);
                motor_tankturn(0,1,255,255,0);
            }
            lastdir = 0;
            loopbreak = 1;
            dir = 3;
        } else if(!dig.l3 && !dig.l2 && dig.l1 && dig.r1 && !dig.r2 && !dig.r3){ //FORWARD        
            reflectance_digital(&dig);
            motor_tankturn(0,0,100,100,0);
            if(y == 14){
                motor_tankturn(0,0,100,100,1500);
                motor_stop(0,0);
                endline = xTaskGetTickCount();
                print_mqtt("Zumo/stop", "%d", endline);
                print_mqtt("Zumo/time", "%d", endline - startline);
            }
        } else if(!dig.l3 && dig.l2 && dig.l1 && !dig.r1 && !dig.r2 && !dig.r3){ //ADJUST RIGHT
            reflectance_digital(&dig);
            motor_tankturn(0,0,25,100,0);
        } else if(!dig.l3 && !dig.l2 && !dig.l1 && dig.r1 && dig.r2 && !dig.r3){ //ADJUST LEFT
            reflectance_digital(&dig);
            motor_tankturn(0,0,100,25,0);
        } else if(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3){ //INTERSECTION
            if(dir == 1){ //GOING FORWARD
                y++;
                lastdir = 1;
                print_mqtt("Zumo/position", "%d %d", x, y);
                reflectance_digital(&dig);
                while(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3){
                    reflectance_digital(&dig);
                    motor_forward(100,0);
                }
                d = Ultra_GetDistance();
                if(y == 12 && x < 0) {
                    motor_tankturn(0,1,255,255,150);
                    dir = 3;
                } else if(y == 12 && x > 0){
                    motor_tankturn(1,0,255,255,150);
                    dir = 2;
                } else if(y == 0){
                    motor_forward(0,0);
                    startline = xTaskGetTickCount();
                    print_mqtt("Zumo/ready", "maze");
                    IR_wait();
                    print_mqtt("Zumo/start", "%d", startline);
                } else if (d <= 20 && x == 2){
                    motor_tankturn(1,0,255,255,150);
                    dir = 2;
                } else if (d <= 20 && x == -2){
                    motor_tankturn(0,1,255,255,150);
                    dir = 3;
                } else if (d <= 20){
                    motor_tankturn(0,1,255,255,150);
                    dir = 3;
                }
            } else if(dir == 2){ //GOING LEFT
                x--;
                lastdir = 2;
                print_mqtt("Zumo/position", "%d %d", x, y);
                reflectance_digital(&dig);
                while(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3){
                    reflectance_digital(&dig);
                    motor_forward(100,0);
                }
                d = Ultra_GetDistance();
                if(y == 12 && x == 0) {
                    motor_tankturn(0,1,255,255,150);
                    dir = 1;
                }
                if(loopbreak == 1 && x == 0){
                    motor_tankturn(0,1,255,255,150);
                    loopbreak = 0;
                    dir = 1;
                }
                if(d <= 20 || x == -2) {
                    motor_tankturn(0,1,255,255,150);
                    dir = 1;
                    d = Ultra_GetDistance();
                }
            } else if(dir == 3){ //GOING RIGHT
                x++;
                lastdir = 3;
                print_mqtt("Zumo/position", "%d %d", x, y);
                reflectance_digital(&dig);
                while(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3){
                    reflectance_digital(&dig);
                    motor_forward(100,0);
                }
                d = Ultra_GetDistance();
                if(y == 12 && x == 0) {
                    motor_tankturn(1,0,255,255,150);
                    dir = 1;
                }
                if(loopbreak == 1 && x == 0){
                    motor_tankturn(1,0,255,255,150);
                    loopbreak = 0;
                    dir = 1;
                }
                if(d <= 20 || x == 2) {
                    motor_tankturn(1,0,255,255,150);
                    dir = 1;
                    d = Ultra_GetDistance();
                }
            }    
        }
    }
}


#endif

/* [] END OF FILE */
