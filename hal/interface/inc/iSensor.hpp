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
    prx
}; //eSensorId

class iSensor
{
//functions
public:
	virtual ~iSensor(){}
	virtual uint8_t read() = 0;
    virtual void charge() = 0;
    virtual void discharge() = 0;
}; //iSensor

#endif //__ISENSOR_H__
