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
    uint8_t count;
    iPin * power;
    iTimer<uint16_t> * timer;
    uint16_t * readings;
    iPin ** sensor;

//functions
public:
    ~ReflectanceSensor();
    ReflectanceSensor(iPin ** sensor, uint8_t count, iPin * power, iTimer<uint16_t> * timer, uint16_t * readings);
    SensorData read();
protected:
private:
    void charge();
    void discharge();
    uint8_t getSensorsState();

}; //ReflectanceSensor

#endif //__REFLECTANCESENSOR_H__
