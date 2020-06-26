/*
 * Pololu.cpp
 *
 * Created: 12/05/2020 15:05:10
 * Author : Mathew.Kuloba
 */ 

#include <stdio.h>
#include <stdlib.h>
#include "ledFactory.h"
#include "motorFactory.h"
#include "sensorFactory.h"
#include "buttonFactory.h"
#include "timerFactory.h"
#include "adc.h"
#include "debug.h"
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

void fn(void);

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
void __cxa_guard_abort (__guard *) {};
    
void __cxa_pure_virtual(void) {};

int main(void)
{
    Debug::setLevel(eDebugLevel::all);
    iPin *dir = PinFactory::create(ePinId::PD6_MOTOR1_DIRECTION);
    iPin *speed = PinFactory::create(ePinId::PD5_MOTOR1_SPEED);
   
    iPin *dir2 = PinFactory::create(ePinId::PB3_MOTOR2_DIRECTION);
    iPin *speed2 = PinFactory::create(ePinId::PD3_MOTOR2_SPEED);
   
    iTimer * timer0 = TimerFactory::create(eTimerId::tmr0, nullptr);
    iTimer * timer2 = TimerFactory::create(eTimerId::tmr2, nullptr);
    timer0->setReload(50);
    timer2->setReload(50);
    
    //_delay_ms(5000);
    //timer0->stop();
    //_delay_ms(5000);
    //timer2->stop();

    while (1)
    {
    }
}

void fn(void)
{
    Debug::write(eDebugLevel::debug, "timer in main");
}

