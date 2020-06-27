/* 
* iPin.h
*
* Created: 18/05/2020 20:08:49
* Author: Mathew.Kuloba
*/


#ifndef __IPIN_H__
#define __IPIN_H__


class iPin
{
//functions
public:
	virtual ~iPin(){}
    virtual void set() = 0;
    virtual void reset() = 0;
    virtual void toggle() = 0;
    virtual void output() = 0;
    virtual void input() = 0;
    virtual bool is_pin_set() = 0;

}; //iPin

#endif //__IPIN_H__
