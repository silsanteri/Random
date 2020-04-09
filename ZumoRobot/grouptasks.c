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

    #if 0
    void zmain(void)
    {

        if(SW1_Read() == 0) {
            printf("\nSOS\n");
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            
            BatteryLed_Write(1);
            vTaskDelay(1500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            BatteryLed_Write(1);
            vTaskDelay(1500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            BatteryLed_Write(1);
            vTaskDelay(1500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
            vTaskDelay(500);
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
            vTaskDelay(500);
        }
    }
    #endif

#if 0
void zmain(void)
{
    int age = 0, time = 0;
    TickType_t start;
    TickType_t end;
    
    while(true){

        start = xTaskGetTickCount();
        printf("\nHow old are you?\n");
        scanf("%d", &age);
        end = xTaskGetTickCount();
        time = end - start;
        //printf("Execution time: %d %d\n", time, age);
        printf("Time: %d ms\n", time);
        
        if(time < 3000 && age <= 21) { // 21
           printf("Super fast dude!\n");
        } else if(time > 3000 && time < 5000 && age <= 21) {
            printf("So medicore.\n");
        } else if(time > 5000 && age <= 21){
            printf("My granny is faster than you!\n");
        } else if(time < 3000 && age >= 22 && age <= 50) { // 22-50
           printf("Be quick or be dead.\n");
        } else if(time > 3000 && time < 5000 && age >= 22 && age <= 50) {
            printf("You're so average.\n");
        } else if(time > 5000 && age >= 22 && age <= 50){
            printf("Have you been drinking something illegal?\n");
        } else if(time < 3000 && age > 50) { // 50
           printf("Still going strong.\n");
        } else if(time > 3000 && time < 5000 && age > 50) {
            printf("You are doing ok for your age.\n");
        } else if(time > 5000 && age > 50){
            printf("Do they still allow you to drive?\n");
        } else {
            printf("Error!\n");
        }
    }
 }   
#endif

#if 0
void zmain(void)
{
    ADC_Battery_Start();        

    int16 adcresult = 0;
    float volts = 0.0;

    printf("\nBoot\n");
    
    while(true)
    {
        ADC_Battery_StartConvert();
        if(ADC_Battery_IsEndConversion(ADC_Battery_WAIT_FOR_RESULT)) {
            adcresult = ADC_Battery_GetResult16();
            volts = 4.8 * adcresult / 4095;
            printf("ADC = %d | Volts = %.2f\r\n",adcresult, volts);
        }
        if(SW1_Read() == 1) {
            printf("ADC = %d | Volts = %.2f\r\n",adcresult, volts);
            if(volts < 4.0){
                
                BatteryLed_Write(1);
                vTaskDelay(100);
                BatteryLed_Write(0);
                vTaskDelay(100);

            } else {
                vTaskDelay(5000);
            }
            
        } else if (SW1_Read() == 0){
            BatteryLed_Write(0);
            vTaskDelay(5000);
        }
    }
 }   
#endif

#if 0
void zmain(void)
{
   while(true){
        
        while(SW1_Read() == 0){
            vTaskDelay(2500);
            
            motor_start();
            motor_turn(200, 200, 0);
            vTaskDelay(1800);
            motor_turn(255, 0, 0);
            vTaskDelay(310);
            motor_turn(255, 255, 0);
            vTaskDelay(1100);
            motor_turn(255, 0, 0);
            vTaskDelay(310);
            motor_turn(255, 255, 0);
            vTaskDelay(1450);
            motor_turn(255, 0, 0);
            vTaskDelay(310);
            motor_turn(255, 180, 0);
            vTaskDelay(1900);
            motor_turn(255, 0, 0);
            vTaskDelay(1250);
            motor_turn(0, 0, 0);
            
        }
    }
}   
#endif

#if 0
void zmain(void)
{
   Ultra_Start();
   motor_start();
   int d = 0;

   while(true){
        
        if(SW1_Read() == 0){
            vTaskDelay(2500);
            
            while(true){
                motor_forward(100, 0);
                d = Ultra_GetDistance();
                
                if (d <= 10){
                    Beep(100, 100);
                    motor_tankturn(1, 0, 100, 100, 500);
                    d = Ultra_GetDistance();
                }
            }
        }
    }
}   
#endif

#if 0
void zmain(void)
{
    struct accData_ data;
    LSM303D_Start();
    motor_start();
    uint8 r, t, d = rand();
    int16 x,y,z = 0;
    bool dl, dr, turn = rand() & 1;
    
    int temp = 1;
    while(true)
    {
        if(SW1_Read() == 0){
            vTaskDelay(2500);
            
			//TEST
			/* while(true){
                motor_forward(255, 0);
                LSM303D_Read_Acc(&data);
                x = data.accX;
                y = data.accY;
                z = data.accZ;
                printf("%d %d %d\n", x, y, z);
                if(x < -10000 && y < -3000) {
                    Beep(100, 232);
                    motor_forward(0,5000);
                }
                
            }*/
            
            while(true)
            {
                LSM303D_Read_Acc(&data);
                x = data.accX;
                y = data.accY;
                z = data.accZ;
                
                if(x < -10000 && y < -3000){
                    LSM303D_Read_Acc(&data);
                x = data.accX;
                y = data.accY;
                z = data.accZ;
                    turn = rand() & 1;
                    Beep(100, 232);
                    motor_tankturn (1, 1, 255, 255, 200);
                    if(turn == 1){
                        dl = 1;
                        dr = 0;
                    } else {
                        dl = 0;
                        dr = 1; 
                    }
                    motor_tankturn (dl, dr, 255, 255, 200);
                } 
                while(x > -10000 && y > -3000) {
                    LSM303D_Read_Acc(&data);
                    x = data.accX;
                    y = data.accY;
                    z = data.accZ;
                    turn = rand() & 1;
                    if(turn == 1){
                        dl = 1;
                        dr = 0;
                    } else {
                        dl = 0;
                        dr = 1; 
                    }
                    motor_forward(255, 0);
                    vTaskDelay(1);
                    temp++;
                    if(temp >= 1500){
                        motor_tankturn(dl, dr, 255, 255, 200);
                        temp = 0;
                    }
                }
            }
        }
    }
 }   
#endif

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    
    IR_flush();

    while(true)
    {
        if(SW1_Read() == 0){
            vTaskDelay(2500);
            motor_forward(100, 450);
            motor_forward(0, 0);
            IR_wait();
            motor_forward(100, 1400);
            motor_forward(0,0);
        }
    }    
 }   
#endif

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    
    IR_flush();

    while(true)
    {
        if(SW1_Read() == 0){
            vTaskDelay(2500);
            motor_forward(100,450);
            motor_forward(0, 0);
            IR_wait();
            motor_forward(100,700);
            motor_tankturn(1,0,100,100,555);
            motor_forward(100,350);
            motor_tankturn(0,1,100,100,555);
            motor_forward(100,700);
            motor_tankturn(0,1,100,100,555);
            motor_forward(100,700);
            motor_forward(0,0);
        }
    }    
 }   
#endif

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    
    IR_flush();

    while(true)
    {
        if(SW1_Read() == 0){
            vTaskDelay(2500);
            motor_forward(100,450);
            motor_forward(0, 0);
            IR_wait();
            motor_forward(100,450);
            motor_tankturn(0,0,200,10,400);
            motor_tankturn(0,0,100,100,300);
            motor_tankturn(0,0,25,200,950);
            motor_tankturn(0,0,100,100,650);
            motor_forward(0,0);
        }
    }    
 }   
#endif

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    IR_flush();
    
    int linecount = 0;
    struct sensors_ dig;

    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    while(SW1_Read() == 1){
        vTaskDelay(100);
    }

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
        
        linecount++;
        
        if(linecount == 1){
            motor_forward(0,0);
            IR_wait();
        } else if(linecount >= 4) {
            motor_forward(0,0);
            motor_stop();
            break;
        }
    }
    
    while(true){
        vTaskDelay(100);
    }
}
#endif

#if 0
void zmain(void)
{
    int ctr = 0;

    
    
    printf("\nBoot\n");
    send_mqtt("Zumo/debug", "Boot");

    
    BatteryLed_Write(0); 

    while(true)
    {
        printf("Ctr: %d, Button: %d\n", ctr, SW1_Read());
        print_mqtt("Zumo/debug", "Ctr: %d, Button: %d", ctr, SW1_Read());

        vTaskDelay(1000);
        ctr++;
    }
 }   
#endif

#if 0
void zmain(void)
{    
    
    int timehour = 0, timemin = 0;
    
    while(true){
    vTaskDelay(10000);
    printf("\nWhat is the time? hour:minute\n");
    scanf("%d:%d", &timehour, &timemin);
    printf("%d %d\n", timehour, timemin);
    
    RTC_Start();
    
    RTC_TIME_DATE now;

    now.Hour = 12;
    now.Min = 34;
    now.Sec = 56;
    now.DayOfMonth = 25;
    now.Month = 9;
    now.Year = 2018;
    RTC_WriteTime(&now);

    while(true)
    {
        if(timehour != 0 && timemin != 0) {
            
            RTC_DisableInt();
            now = *RTC_ReadTime();
            RTC_EnableInt();

            if(SW1_Read() == 0){
                printf("%2d:%02d.%02d\n", now.Hour, now.Min, now.Sec);
                print_mqtt("Zumo", "%2d:%02d.%02d\n", now.Hour, now.Min, now.Sec);
                vTaskDelay(250);
            }
        }
    }
    }
 }   
#endif

#if 0
void zmain(void)
{
   Ultra_Start();
   motor_start();
   bool dl, dr, turn = rand() & 1;
   int d = 0;

   while(true){
        
        if(SW1_Read() == 0){
            vTaskDelay(2500);
            
            while(true){
                motor_forward(100, 0);
                d = Ultra_GetDistance();
                
                if (d <= 10){
                    Beep(100, 100);
                    turn = rand() & 1;
                    if(turn == 1){
                        print_mqtt("Zumo/turn", "left\n");
                        dl = 1;
                        dr = 0;
                    } else {
                        print_mqtt("Zumo/turn", "right\n");
                        dl = 0;
                        dr = 1; 
                    }
                    
                    motor_tankturn(1, 1, 255, 255, 200);
                    motor_tankturn(dl, dr, 255, 255, 200);
                    d = Ultra_GetDistance();
                }
            }
        }
    }
}   
#endif

#if 0
void zmain(void)
{
    IR_Start();
    motor_start();
    IR_flush();
    clock_t start_t, end_t, lap_t;
    
    struct sensors_ dig;
    
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    while(SW1_Read() == 1){
        vTaskDelay(100);
    }

    while(true){
    
        reflectance_digital(&dig);
        
        while(!(dig.l3 && dig.l2 && dig.l1 && dig.r1 && dig.r2 && dig.r3))
        {
            reflectance_digital(&dig);
            motor_forward(100,0);
        }
        
        motor_forward(0,0);
        end_t = clock();
        IR_wait();
        start_t = clock();
        lap_t = end_t - start_t;
        print_mqtt("Zumo/lap", "%ld", lap_t);
    
    while(true){
        vTaskDelay(100);
    }
    }
}
#endif

/* [] END OF FILE */
