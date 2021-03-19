/*
 * Pololu.cpp
 *
 * Created: 12/05/2020 15:05:10
 * Author : Mathew.Kuloba
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "iPin.hpp"
#include "iLed.hpp"
#include "iMotor.hpp"
#include "iSensor.hpp"
#include "iButton.hpp"
#include "iTimer.hpp"
#include "iDebug.hpp"
#include "iPwm.hpp"
#include <util/delay.h>

void * operator new(size_t size);
void operator delete(void * ptr);

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);

extern "C" void __cxa_pure_virtual(void);

void * operator new(size_t size)
{
    return malloc(size);
}

void operator delete(void * ptr)
{
    free(ptr);
}

void operator delete(void* ptr, unsigned int size)
{
    (void)(size);
    free(ptr);
}

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

iMotor * motor_1;
iMotor * motor_2;
iPwm * pwm_1;
iPwm * pwm_2;

int main()
{
    static const uint8_t speed = 30;

    motor_1 = iMotor::create(eMotorId::motor_1);
    motor_2 = iMotor::create(eMotorId::motor_2);

    motor_1->forward(speed);
    motor_2->forward(speed);

    while (1)
    {
        
    }
}
