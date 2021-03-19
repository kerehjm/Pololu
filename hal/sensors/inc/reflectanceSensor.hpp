/* 
* ReflectanceSensor.h
*
* Created: 16/05/2020 10:48:22
* Author: Mathew.Kuloba
*/


#ifndef __REFLECTANCESENSOR_H__
#define __REFLECTANCESENSOR_H__

class ReflectanceSensor : public iSensor
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
    ~ReflectanceSensor();
    ReflectanceSensor(iPin * sensor, iPin * power, iTimer<uint16_t> * timer);
    uint8_t read();
protected:
private:
    void charge();
    void discharge();

}; //ReflectanceSensor

#endif //__REFLECTANCESENSOR_H__
