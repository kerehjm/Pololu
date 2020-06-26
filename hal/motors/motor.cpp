/* 
* Motor.cpp
*
* Created: 15/05/2020 20:43:36
* Author: Mathew.Kuloba
*/


#include "motor.h"
#include <string.h>

// default destructor
Motor::~Motor()
{
} //~Motor

Motor::Motor(eMotorId motorId, iTimer *timer, iPin *direction, iPin *speed)
{
    this->motorId = motorId;
    this->direction = direction;
    this->speed = speed;
    this->timer = timer;
    //this->off();
    
    Debug::write(eDebugLevel::debug, "Motor [%d] init", motorId);
} //MotorPinControl

void Motor::off()
{
    this->direction->reset();
    this->speed->reset();
    timer->stop();
    
    Debug::write(eDebugLevel::debug, "motor [%d] off", motorId);
}

void Motor::forward(uint8_t speed)
{
    this->direction->set();
    this->speed->reset();
    timer->setReload(speed);
    //timer->start();
    
    Debug::write(eDebugLevel::debug, "motor [%d] forward", motorId);
}

void Motor::reverse(uint8_t speed)
{
    this->direction->reset();
    this->speed->set();
    timer->setReload(speed);
    //timer->startInverted();
    
    Debug::write(eDebugLevel::debug, "motor [%d] reverse", motorId);
}

void Motor::brake()
{
    this->direction->set();
    this->speed->set();
    timer->setReload(0);
    timer->stop();
    
    Debug::write(eDebugLevel::debug, "motor [%d] brake", motorId);
}
