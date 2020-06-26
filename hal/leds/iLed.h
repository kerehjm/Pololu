/* 
* iLed.h
*
* Created: 08/06/2020 16:33:54
* Author: Mathew.Kuloba
*/


#ifndef __ILED_H__
#define __ILED_H__


class iLed
{
//functions
public:
	virtual ~iLed(){}
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;

}; //iLed

#endif //__ILED_H__
