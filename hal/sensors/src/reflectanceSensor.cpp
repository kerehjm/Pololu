/* 
* ReflectanceSensor.cpp
*
* Created: 16/05/2020 10:48:22
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include <util/delay.h>
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iPin.hpp"
#include "reflectanceSensor.hpp"
#include "iDebug.hpp"

// #include <avr/io.h>
#include <string.h>

#define MAX_VALUE 2000 //800uS

// default constructor  
ReflectanceSensor::ReflectanceSensor(
    iPin * sensor[],
    uint8_t count,
    iPin * power,
    iTimer<uint16_t> * timer,
    uint16_t * readings)
{
    this->count = count;
    this->power = power;
    this->timer = timer;
    this->readings = readings;

    for (uint8_t i = 0; i < count; i++)
    {
        this->sensor[i] = sensor[i];
    }
} //ReflectanceSensor

// default destructor
ReflectanceSensor::~ReflectanceSensor()
{
} //~ReflectanceSensor

SensorData ReflectanceSensor::read()
{
    uint16_t last_time;
    uint16_t time = 0;
    uint8_t last_c = getSensorsState();
    memset(readings, 0, count);
    SensorData data = SensorData(count, readings);

    charge();    //Charge sensor
    _delay_us(13);      //Delay 13 microseconds
    discharge(); //Discharge sensors

    last_time = timer->getCount();

    while (time < MAX_VALUE)
    {
        uint16_t delta_time = timer->getCount() - last_time;
        time += delta_time;
        last_time += delta_time;

        // continue immediately if there is no change
        uint8_t state = getSensorsState();
        if (state == last_c)
        {
            continue;
        }

        // save the last observed values
        last_c = state;

        for (uint8_t i = 0; i < count; i++)
        {
            if (readings[i] == 0 && !sensor[i]->isSet())
            {
                readings[i] = time;
            }
        }
        if (last_time == timer->getCount())
        {
            //not running exit TODO
            break;
        }
    }

    //Set to max if time elapsed with pin still high
    for(uint8_t i = 0; i < count; i++)
    {
        if (!readings[i])
        {
            readings[i] = MAX_VALUE;
        }
    }
    data.size = count;
    data.readings = readings;
    return data;
}

void ReflectanceSensor::charge()
{
    for (uint8_t i = 0; i < count; i++)
    {
        sensor[i]->output();
        sensor[i]->set();
    }
}

void ReflectanceSensor::discharge()
{
    for (uint8_t i = 0; i < count; i++)
    {
        sensor[i]->input();
        sensor[i]->reset(); //Turn off pullups
    }
}

uint8_t ReflectanceSensor::getSensorsState()
{
    uint8_t state = 0;
    for (uint8_t i = 0; i < count; i++)
    {
        state |= (sensor[i]->isSet() << i);
    }
    return state;
}