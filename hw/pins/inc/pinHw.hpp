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
    void init(ePinId pinId);
    void set(ePinId pinId);
    void reset(ePinId pinId);
    void toggle(ePinId pinId);
    void output(ePinId pinId);
    void input(ePinId pinId);
    bool is_pin_set(ePinId pinId);
protected:
private:
    PinHw();

}; //PinHw

#endif //__PIN_H__
