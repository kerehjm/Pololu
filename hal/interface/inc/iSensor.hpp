/* 
* iSensor.h
*
* Created: 18/05/2020 18:31:16
* Author: Mathew.Kuloba
*/


#ifndef __ISENSOR_H__
#define __ISENSOR_H__

enum class eSensorId
{
    rl0,
    rl1,
    rl2,
    rl3,
    rl4,
}; //eSensorId

class iSensor
{
//functions
public:
    static iSensor * createReflectance(eSensorId sensorId, iTimer<uint16_t> * timer);
    static iSensor * createProximity(iTimer<uint16_t> * timer);
    virtual ~iSensor(){}
    virtual uint8_t read() = 0;
}; //iSensor

#endif //__ISENSOR_H__
