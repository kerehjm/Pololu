/* 
* Sensor.cpp
*
* Created: 21/05/2020 18:09:36
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include "iSensor.hpp"
#include "iTimer.hpp"
#include "iPin.hpp"
#include "sensor.hpp"

// default constructor
Sensor::Sensor()
{
} //Sensor

// default destructor
Sensor::~Sensor()
{
} //~Sensor

uint8_t Sensor::read()
{
    return 0;
}

void Sensor::charge()
{

}

void Sensor::discharge()
{

}