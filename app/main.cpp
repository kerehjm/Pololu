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
void button_a_callback(void);
void button_b_callback(void);
void button_c_callback(void);

iTimer<uint16_t> * timer;
iSensor * sensor;
iDebug * debug;
iLcd * lcd;
iMotor * motor1;
iMotor * motor2;
iButton * button_a;
iButton * button_b;
iButton * button_c;

int main()
{
    iDebug::init(eDebugLevel::all);
    iDebug::debug("Init");
    timer = iTimer<uint16_t>::create(tick);
    lcd = iLcd::create();
    motor1 = iMotor::create(eMotorId::motor_1);
    motor2 = iMotor::create(eMotorId::motor_2);
    sensor = iSensor::createReflectance(timer);
    button_a = iButton::create(eButtonId::a, button_a_callback);
    button_b = iButton::create(eButtonId::b, button_b_callback);
    button_c = iButton::create(eButtonId::c, button_c_callback);

    while (1)
    {
    }
}

void tick(void)
{
    SensorData data = sensor->read();
    for (uint8_t i = 0; i < data.size; i++)
    {
        iDebug::debug("Sensor[%d]: %d", i, data.readings[i] );
    }
    lcd->print("S:%d", data.readings[0]);
}

void button_a_callback(void)
{
    motor1->forward(100);
    motor2->forward(100);
}

void button_b_callback(void)
{
    timer->start();
    motor1->off();
    motor2->off();
}

void button_c_callback(void)
{
    motor1->reverse(100);
    motor2->reverse(100);
}
