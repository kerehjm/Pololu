/* 
* Motor.cpp
*
* Created: 15/05/2020 20:43:36
* Author: Mathew.Kuloba
*/

#include <string.h>
#include <stdint.h>
#include "iTimer.hpp"
#include "iPin.hpp"
#include "iMotor.hpp"
#include "iDebug.hpp"
#include "motor.hpp"

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
    
    debug->write(eDebugLevel::debug, "Motor [%d] init", motorId);
} //MotorPinControl

Motor::Motor(eMotorId motorId, iTimer *timer, iPin *direction, iPin *speed, iDebug * debug)
{
    this->motorId = motorId;
    this->direction = direction;
    this->speed = speed;
    this->timer = timer;
    //this->off();
    
    debug->write(eDebugLevel::debug, "Motor [%d] init", motorId);
} //MotorPinControl

void Motor::off()
{
    this->direction->reset();
    this->speed->reset();
    timer->stop();
    
    debug->write(eDebugLevel::debug, "motor [%d] off", motorId);
}

void Motor::forward(uint8_t speed)
{
    this->direction->set();
    this->speed->reset();
    timer->reload(speed);
    //timer->start();
    
    debug->write(eDebugLevel::debug, "motor [%d] forward", motorId);
}

void Motor::reverse(uint8_t speed)
{
    this->direction->reset();
    this->speed->set();
    timer->reload(speed);
    //timer->startInverted();
    
    debug->write(eDebugLevel::debug, "motor [%d] reverse", motorId);
}

void Motor::brake()
{
    this->direction->set();
    this->speed->set();
    timer->reload(0);
    timer->stop();
    
    debug->write(eDebugLevel::debug, "motor [%d] brake", motorId);
}
