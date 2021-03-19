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
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iButton.hpp"
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

void tick(void);

iTimer<uint16_t> * timer;
iSensor * reflax_0;
iSensor * reflax_1;
iDebug * debug;

int main()
{
    iDebug::init(eDebugLevel::all);
    timer = iTimer<uint16_t>::create(tick);
    timer->start();

    reflax_0 = iSensor::createReflectance(eSensorId::rl0, timer);
    reflax_1 = iSensor::createReflectance(eSensorId::rl4, timer);

    while (1)
    {
        
    }
}

void tick(void)
{
    iDebug::log(eDebugLevel::debug, "Sensor data: %d", reflax_0->read());
    iDebug::log(eDebugLevel::debug, "Sensor data: %d", reflax_1->read());
}
