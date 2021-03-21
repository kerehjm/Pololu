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
#include "iPwm.hpp"
#include "motor.hpp"

// default destructor
Motor::~Motor()
{
} //~Motor

Motor::Motor(eMotorId motorId, iPwm * pwm, iPin * direction, iPin * speed)
{
    this->motorId = motorId;
    this->direction = direction;
    this->speed = speed;
    this->pwm = pwm;
    //this->off();
}

void Motor::off()
{
    pwm->stop();
    pwm->selectChannel(ePwmChannel::channel_none);
    pwm->setDutyCycle(ePwmChannel::channel_1, 0);
    pwm->setDutyCycle(ePwmChannel::channel_2, 0);
    direction->reset();
    speed->reset();
}

void Motor::forward(uint8_t dc)
{
    pwm->stop();
    speed->set();
    pwm->setDutyCycle(ePwmChannel::channel_1, 0); //TODO find out why
    pwm->setDutyCycle(ePwmChannel::channel_2, dc);
    pwm->selectChannel(ePwmChannel::channel_2);
    pwm->start();
}

void Motor::reverse(uint8_t dc)
{
    pwm->stop();
    direction->set();
    pwm->setDutyCycle(ePwmChannel::channel_1, dc);
    pwm->setDutyCycle(ePwmChannel::channel_2, 0);
    pwm->selectChannel(ePwmChannel::channel_1);
    pwm->start();
}

void Motor::brake()
{
    pwm->stop();
    pwm->selectChannel(ePwmChannel::channel_none);
    pwm->setDutyCycle(ePwmChannel::channel_1, 0);
    pwm->setDutyCycle(ePwmChannel::channel_2, 0);
    direction->set();
    speed->set();
}
