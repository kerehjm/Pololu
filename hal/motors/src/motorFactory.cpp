/* 
* MotorFactory.cpp
*
* Created: 15/05/2020 21:45:23
* Author: Mathew.Kuloba
*/


#include "motorFactory.h"

iMotor *MotorFactory::create(eMotorId motor_id)
{
    iPin *dir = nullptr;
    iPin *speed = nullptr;
    iTimer *tmr = nullptr;
    iMotor *motor = nullptr;
    
    switch (motor_id)
    {
        case eMotorId::motor_1:
            dir = PinFactory::create(ePinId::PD6_MOTOR1_DIRECTION);
            speed = PinFactory::create(ePinId::PD5_MOTOR1_SPEED);
            tmr = new Timer0();          
            break;
        case eMotorId::motor_2:
            dir = PinFactory::create(ePinId::PB3_MOTOR2_DIRECTION);
            speed = PinFactory::create(ePinId::PD3_MOTOR2_SPEED);
            tmr = new Timer2();
            break;
    }
    motor = new Motor(motor_id, tmr, dir, speed);
    return motor;
}
