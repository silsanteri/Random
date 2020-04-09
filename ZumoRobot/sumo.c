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
    LSM303D_Start();
    motor_start();
    IR_flush();
    
    TickType_t startline;
    TickType_t endline;
    TickType_t hit;
    
    int16 x,y,z = 0;
    struct accData_ data;
    struct sensors_ dig;

    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    while(SW1_Read() == 1){
        vTaskDelay(1);
    }
    vTaskDelay(1000);
    while(true){
        reflectance_digital(&dig);
        while(!(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3))
        {
            reflectance_digital(&dig);
            motor_forward(100,0);
        }
        while(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3)
        {
            reflectance_digital(&dig);
            motor_forward(100,0);
        }

        motor_forward(0,0);
        startline = xTaskGetTickCount();
        print_mqtt("Zumo/ready", "zumo");
        IR_wait();
        print_mqtt("Zumo/start", "%d", startline);
        motor_forward(250,500);
        while(true){
            LSM303D_Read_Acc(&data);
            x = data.accX;
            y = data.accY;
            z = data.accZ;
            if(SW1_Read() == 0){
                endline = xTaskGetTickCount();
                motor_forward(0,0);
                motor_stop();
                print_mqtt("Zumo/stop", "%d", endline);
                print_mqtt("Zumo/time", "%d", endline - startline);
                break;
            }
            if(x < -10000 && y < -3000){
                hit = xTaskGetTickCount();
                print_mqtt("Zumo/hit", "%d", hit);
            }
         motor_tankturn(1,0,255,255,0);
        }
    }
    
    while(true){
        vTaskDelay(100);
    }
}
#endif

/* [] END OF FILE */
