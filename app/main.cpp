/*
 * Pololu.cpp
 *
 * Created: 12/05/2020 15:05:10
 * Author : Mathew.Kuloba
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "iPin.hpp"
#include "iLed.hpp"
#include "iMotor.hpp"
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iButton.hpp"
#include "iDebug.hpp"
#include "iPwm.hpp"
#include "iLcd.hpp"

void * operator new(size_t size);
void operator delete(void * ptr);

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);

// extern "C" void __cxa_pure_virtual(void);

extern "C" void __cxa_pure_virtual() { while (1); }

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
iSensor * sensor;
iDebug * debug;
iLcd * lcd;
iMotor * motor1;
iMotor * motor2;

int main()
{
    iDebug::init(eDebugLevel::all);
    timer = iTimer<uint16_t>::create(tick);
    lcd = iLcd::create();
    motor1 = iMotor::create(eMotorId::motor_1);
    motor2 = iMotor::create(eMotorId::motor_2);
    sensor = iSensor::createReflectance(timer);

    timer->start();
    motor1->forward(100);
    motor2->reverse(100);

    while (1)
    {
    }
}

void tick(void)
{
    motor1->off();
    motor2->off();
    SensorData data = sensor->read();
    for (uint8_t i = 0; i < data.size; i++)
    {
        iDebug::debug("Sensor[%d]: %d", i, data.readings[i] );
    }
    lcd->print("S:%d", data.readings[0]);
}
