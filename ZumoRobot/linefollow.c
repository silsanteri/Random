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
    IR_Start();
    motor_start();
    IR_flush();
    
    TickType_t startline;
    TickType_t endline;
    TickType_t miss;
    TickType_t line;
    
    struct sensors_ dig;
    int linecount = 0;
    bool bonuscounter = 0;

    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    while(SW1_Read() == 1){
        vTaskDelay(1);
    }
    vTaskDelay(1000);
    while(true){
        reflectance_digital(&dig);
        if(!dig.l3 && !dig.l2 && dig.l1 && dig.r1 && !dig.r2 && !dig.r3 && bonuscounter == 1){ //FORWARD BONUS
            bonuscounter = 0;
            line = xTaskGetTickCount();
            print_mqtt("Zumo/line", "%d", line);
            reflectance_digital(&dig);
            motor_forward(255,0);
        } else if(!dig.l3 && !dig.l2 && dig.l1 && dig.r1 && !dig.r2 && !dig.r3){ //FORWARD
            reflectance_digital(&dig);
            motor_forward(255,0);
        } else if(!dig.l3 && dig.l2 && dig.l1 && !dig.r1 && !dig.r2 && !dig.r3){ //RIGHT
            reflectance_digital(&dig);
            motor_tankturn(0,0,255,175,0);
        } else if(!dig.l3 && !dig.l2 && !dig.l1 && dig.r1 && dig.r2 && !dig.r3){ //LEFT
            reflectance_digital(&dig);
            motor_tankturn(0,0,175,255,0);
        } else if(!dig.l3 && !dig.l2 && !dig.l1 && !dig.r1 && dig.r2 && dig.r3){ //HARD RIGHT
            reflectance_digital(&dig);
            motor_tankturn(0,0,200,100,0);
        } else if(dig.l3 && dig.l2 && !dig.l1 && !dig.r1 && !dig.r2 && !dig.r3){ //HARD LEFT
            reflectance_digital(&dig);
            motor_tankturn(0,0,100,255,0);
        } else if(!dig.l3 && !dig.l2 && !dig.l1 && !dig.r1 && !dig.r2 && dig.r3){ //EXTRA HARD RIGHT
            reflectance_digital(&dig);
            motor_tankturn(0,1,255,255,0);
        } else if(dig.l3 && !dig.l2 && !dig.l1 && !dig.r1 && !dig.r2 && !dig.r3){ //EXTRA HARD LEFT
            reflectance_digital(&dig);
            motor_tankturn(1,0,255,255,0);
        } else if(dig.l3 && dig.l2 && !dig.l1 && !dig.r1 && dig.r2 && dig.r3 && bonuscounter == 0){ //BONUS
            bonuscounter = 1;
            miss = xTaskGetTickCount();
            print_mqtt("Zumo/miss", "%d", miss);
        } else if(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3){ //LINE
            reflectance_digital(&dig);
            
            while(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3){
                reflectance_digital(&dig);
                motor_forward(100,0);
            }
            
            linecount++;
            
            if(linecount == 1){
                motor_forward(0,0);
                startline = xTaskGetTickCount();
                print_mqtt("Zumo/ready", "line");
                IR_wait();
            } else if(linecount >= 3) {
                motor_forward(0,0);
                motor_stop();
                endline = xTaskGetTickCount();
                print_mqtt("Zumo/start", "%d", startline);
                print_mqtt("Zumo/stop", "%d", endline);
                print_mqtt("Zumo/time", "%d", endline - startline);
                break;
            }
        }
    }
}


#endif

/* [] END OF FILE */
