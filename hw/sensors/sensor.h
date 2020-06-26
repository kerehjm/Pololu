/* 
* Sensor.h
*
* Created: 21/05/2020 18:09:37
* Author: Mathew.Kuloba
*/


#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "iSensor.h"

class Sensor : public iSensor
{
//variables
public:
protected:
    iPin *power;
    iPin *sensor;
    iTimer *timer;
private:

//functions
public:
	Sensor();
	~Sensor();
protected:
private:
	Sensor( const Sensor &c );
	Sensor& operator=( const Sensor &c );

}; //Sensor

#endif //__SENSOR_H__
