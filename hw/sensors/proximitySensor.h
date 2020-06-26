/* 
* ProximitySensor.h
*
* Created: 16/05/2020 11:26:19
* Author: Mathew.Kuloba
*/


#ifndef __PROXIMITYSENSOR_H__
#define __PROXIMITYSENSOR_H__

#include "sensor.h"

class ProximitySensor : public Sensor
{
//variables
public:
protected:
private:

//functions
public:
	ProximitySensor(iPin *pin, iPin *power, iTimer *timer);
	~ProximitySensor();
    uint8_t read();
protected:
    void charge();
    void discharge();
private:

}; //ProximitySensor

#endif //__PROXIMITYSENSOR_H__
