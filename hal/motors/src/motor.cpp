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
#include "iTimer.hpp"
#include "motor.hpp"

// default destructor
Motor::~Motor()
{
} //~Motor

Motor::Motor(eMotorId motorId, iTimer<uint8_t> *timer, iPin *direction, iPin *speed)
{
    this->motorId = motorId;
    this->direction = direction;
    this->speed = speed;
    this->timer = timer;
    //this->off();
}

void Motor::off()
{
    this->direction->reset();
    // this->speed->reset();
    timer->stop();
}

void Motor::forward(uint8_t speed)
{
    timer->stop();
    this->direction->reset();
    // this->speed->reset();
    timer->setFrequency(speed);
    timer->start();
}

void Motor::reverse(uint8_t speed)
{
    timer->stop();
    this->direction->set();
    // this->speed->reset();
    timer->setFrequency(speed);
    timer->start();
}

void Motor::brake()
{
    timer->stop();
    // this->direction->set();
    this->speed->set();
}
