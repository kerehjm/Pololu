/* 
* ProximitySensor.h
*
* Created: 16/05/2020 11:26:19
* Author: Mathew.Kuloba
*/


#ifndef __PROXIMITYSENSOR_H__
#define __PROXIMITYSENSOR_H__

class ProximitySensor : public iSensor
{
//variables
public:
protected:
private:
    iPin * sensor;
    iPin * power;
    iTimer<uint16_t> * timer;

//functions
public:
    ProximitySensor(iPin *pin, iPin *power, iTimer<uint16_t> *timer);
    ~ProximitySensor();
    SensorData read();
protected:
private:
    void charge();
    void discharge();
}; //ProximitySensor

#endif //__PROXIMITYSENSOR_H__
