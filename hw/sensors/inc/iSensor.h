/* 
* iSensor.h
*
* Created: 18/05/2020 18:31:16
* Author: Mathew.Kuloba
*/


#ifndef __ISENSOR_H__
#define __ISENSOR_H__

#ifndef F_CPU
#define F_CPU 20000000
#endif

#include <stdint.h>
#include <util/delay.h>
#include "iTimer.h"
#include "pin.h"

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
