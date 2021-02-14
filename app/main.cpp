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
void pwm_init()
{
    TCCR2A |= (1<<WGM20)|(1<<COM2A1)|(1<<COM2A1);
    TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22);

    DDRB |= (1<<PB3);

    OCR2A = 50;

    TCCR0A |= (1<<WGM00)|(1<<COM0A1)|(1<<WGM01);
    TCCR0B |= (1<<CS00) | (1<<CS02);

    DDRD |= (1<<PD6);

    OCR0A = 50;
}

void time(void);

int main()
{
    iPin::create(ePinId::PB3_MOTOR2_DIRECTION, ePinDir::OUTPUT, ePinState::LOW);
    iPin::create(ePinId::PD3_MOTOR2_SPEED, ePinDir::OUTPUT, ePinState::LOW);

    iPin::create(ePinId::PD6_MOTOR1_DIRECTION, ePinDir::OUTPUT, ePinState::LOW);
    iPin::create(ePinId::PD5_MOTOR1_SPEED, ePinDir::OUTPUT, ePinState::LOW);

    iTimer::create(eTimerId::pwm);
    iTimer::create(eTimerId::pwm2);

    while (1)
    {
    }
}
