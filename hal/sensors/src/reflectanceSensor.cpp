/* 
* ReflectanceSensor.cpp
*
* Created: 16/05/2020 10:48:22
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include "iSensor.hpp"
#include "iTimer.hpp"
#include "iPin.hpp"
#include "sensor.hpp"
#include "reflectanceSensor.hpp"

#define MAX_VALUE 110

// default constructor
ReflectanceSensor::ReflectanceSensor(iPin *sensor, iPin *power, iTimer<uint16_t> *timer)
{
    this->sensor = sensor;
    this->power = power;
    this->timer = timer;
    power->set();
} //ReflectanceSensor

// default destructor
ReflectanceSensor::~ReflectanceSensor()
{
} //~ReflectanceSensor

uint8_t ReflectanceSensor::read()
{
    uint8_t last_time;
    uint8_t delta_time;
    uint8_t time = 0;
    uint8_t last_c = sensor->isSet();
    uint8_t reading = 0;

    charge();    //Charge sensor
    // _delay_us(13);      //Delay 13 microseconds
    discharge(); //Discharge sensors

    last_time = timer->getCount();

    while (time < MAX_VALUE)
    {
        delta_time = timer->getCount() - last_time;
        time += delta_time;
        last_time += delta_time;

        // continue immediately if there is no change
        if (sensor->isSet() == last_c)
            continue;

        // save the last observed values
        last_c = sensor->isSet();

        if (reading == 0 && sensor->isSet() == 0)
        {
            reading = time;
        }
    }

    //Set to max if time elapsed with pin still high
    if (!reading)
    {
        reading = MAX_VALUE;
    }
    return reading;
}

void ReflectanceSensor::charge()
{
    sensor->output();
    sensor->set();
}

void ReflectanceSensor::discharge()
{
    sensor->input();
    sensor->reset(); //Turn off pullups
}