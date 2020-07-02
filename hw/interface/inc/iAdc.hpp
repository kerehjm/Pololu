/* 
* iAdc.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __IADC_H__
#define __IADC_H__

#include "eAdcId.hpp"

class iAdc
{
//functions
public:
    virtual ~iAdc(){}
    virtual void init() = 0;
    virtual void on() = 0;
    virtual void off() = 0;
    virtual uint8_t read(eAdcId channel) = 0;
}; //iAdc

#endif //__IADC_H__
