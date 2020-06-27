/* 
* ProximitySensor.cpp
*
* Created: 16/05/2020 11:26:19
* Author: Mathew.Kuloba
*/


#include "proximitySensor.h"

// default constructor
ProximitySensor::ProximitySensor(iPin *pin, iPin *power, iTimer *timer)
{
    this->sensor = sensor;
    this->power = power;
    this->timer = timer;
} //ProximitySensor

// default destructor
ProximitySensor::~ProximitySensor()
{
} //~ProximitySensor

uint8_t ProximitySensor::read()
{
    sensor->set();
    _delay_us(10);
    sensor->reset();
    return 0;
}

void ProximitySensor::charge()
{
    
}

void ProximitySensor::discharge()
{
    
}