/* 
* Motor.cpp
*
* Created: 15/05/2020 20:43:36
* Author: Mathew.Kuloba
*/

#include <string.h>
#include <stdint.h>
#include "iPin.hpp"
#include "iMotor.hpp"
#include "iDebug.hpp"
#include "iTimerHw.hpp"
#include "motor.hpp"

// default destructor
Motor::~Motor()
{
} //~Motor

Motor::Motor(eMotorId motorId, iTimerHw<uint8_t> *timer, iPin *direction, iPin *speed)
{
    this->motorId = motorId;
    this->direction = direction;
    this->speed = speed;
    this->timer = timer;
    //this->off();
    
    debug->log(eDebugLevel::debug, "Motor [%d] init", motorId);
} //MotorPinControl

Motor::Motor(eMotorId motorId, iTimerHw<uint8_t> *timer, iPin *direction, iPin *speed, iDebug * debug)
{
    this->motorId = motorId;
    this->direction = direction;
    this->speed = speed;
    this->timer = timer;
    //this->off();
    
    debug->log(eDebugLevel::debug, "Motor [%d] init", motorId);
} //MotorPinControl

void Motor::off()
{
    this->direction->reset();
    this->speed->reset();
    timer->stop();
    
    debug->log(eDebugLevel::debug, "motor [%d] off", motorId);
}

void Motor::forward(uint8_t speed)
{
    this->direction->set();
    this->speed->reset();
    timer->setReload(speed);
    //timer->start();
    
    debug->log(eDebugLevel::debug, "motor [%d] forward", motorId);
}

void Motor::reverse(uint8_t speed)
{
    this->direction->reset();
    this->speed->set();
    timer->setReload(speed);
    //timer->startInverted();
    
    debug->log(eDebugLevel::debug, "motor [%d] reverse", motorId);
}

void Motor::brake()
{
    uint8_t dc = 0;
    this->direction->set();
    this->speed->set();
    timer->setReload(dc);
    timer->stop();
    
    debug->log(eDebugLevel::debug, "motor [%d] brake", motorId);
}
