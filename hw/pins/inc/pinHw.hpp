/* 
* PinHw.h
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/


#ifndef __PIN_H__
#define __PIN_H__

#include "iPinHw.hpp"
#include "pinPortMap.hpp"

class PinHw : public iPinHw
{
//variables
public:
protected:
private:
    static PinPortMap pin;

//functions
public:
    ~PinHw();
    void init(eHwPinId pinId);
    void set(eHwPinId pinId);
    void reset(eHwPinId pinId);
    void toggle(eHwPinId pinId);
    void output(eHwPinId pinId);
    void input(eHwPinId pinId);
    bool is_pin_set(eHwPinId pinId);
protected:
private:
    PinHw();

}; //PinHw

#endif //__PIN_H__
