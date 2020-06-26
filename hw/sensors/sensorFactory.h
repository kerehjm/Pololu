/* 
* SensorFactory.h
*
* Created: 16/05/2020 12:24:07
* Author: Mathew.Kuloba
*/


#ifndef __SENSORFACTORY_H__
#define __SENSORFACTORY_H__

#include "iSensor.h"
#include "eSensorId.h"
#include "proximitySensor.h"
#include "reflectanceSensor.h"
#include "pinFactory.h"
#include "timerFactory.h"

class SensorFactory
{
//variables
public:
protected:
private:

//functions
public:
        static iSensor *create(eSensorId sensor_id);
protected:
private:
    SensorFactory();
    ~SensorFactory();
}; //SensorFactory

#endif //__SENSORFACTORY_H__
