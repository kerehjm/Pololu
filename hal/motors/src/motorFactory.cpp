#include <stdint.h>
#include "iPin.hpp"
#include "iDebug.hpp"
#include "iMotor.hpp"
#include "iTimerHw.hpp"
#include "motor.hpp"

iMotor * iMotor::create(eMotorId motorId)
{
    iMotor * motor = nullptr;
    iTimerHw<uint8_t> * timer = nullptr;
    iPin *  directionPin = nullptr;
    iPin *  speedPin = nullptr;

    switch (motorId)
    {
    case eMotorId::motor_1:
        timer = iTimerHw<uint8_t>::createPwm(eTimerHwIdU8::tmr0, 0);
        directionPin = iPin::create(ePinId::PD6_MOTOR1_DIRECTION, ePinDir::OUTPUT, ePinState::HIGH);
        speedPin = iPin::create(ePinId::PD5_MOTOR1_SPEED, ePinDir::OUTPUT, ePinState::LOW);
        motor = new Motor(motorId, timer, directionPin, speedPin);
        break;
    case eMotorId::motor_2:
        timer = iTimerHw<uint8_t>::createPwm(eTimerHwIdU8::tmr2, 0);
        directionPin = iPin::create(ePinId::PB3_MOTOR2_DIRECTION, ePinDir::OUTPUT, ePinState::HIGH);
        speedPin = iPin::create(ePinId::PD3_MOTOR2_SPEED, ePinDir::OUTPUT, ePinState::LOW);
        motor = new Motor(motorId, timer, directionPin, speedPin);
        break;
    default:
        break;
    }
    return motor;
}