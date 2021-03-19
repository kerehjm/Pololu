#include <stdint.h>
#include "iPin.hpp"
#include "iDebug.hpp"
#include "iMotor.hpp"
#include "iPwm.hpp"
#include "motor.hpp"

iMotor * iMotor::create(eMotorId motorId)
{
    iMotor * motor = nullptr;
    iPwm * pwm = nullptr;
    iPin *  directionPin = nullptr;
    iPin *  speedPin = nullptr;

    switch (motorId)
    {
    case eMotorId::motor_1:
        pwm = iPwm::create(ePwmId::pwm_1);
        speedPin = iPin::create(ePinId::PD6_MOTOR1_DIRECTION, ePinDir::OUTPUT, ePinState::LOW);
        directionPin = iPin::create(ePinId::PD5_MOTOR1_SPEED, ePinDir::OUTPUT, ePinState::LOW);
        motor = new Motor(motorId, pwm, directionPin, speedPin);
        break;
    case eMotorId::motor_2:
        pwm = iPwm::create(ePwmId::pwm_2);
        speedPin = iPin::create(ePinId::PB3_MOTOR2_DIRECTION, ePinDir::OUTPUT, ePinState::LOW);
        directionPin = iPin::create(ePinId::PD3_MOTOR2_SPEED, ePinDir::OUTPUT, ePinState::LOW);
        motor = new Motor(motorId, pwm, directionPin, speedPin);
        break;
    default:
        break;
    }
    return motor;
}