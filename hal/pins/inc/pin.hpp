/* 
* Pin.h
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/


#ifndef __PIN_H__
#define __PIN_H__

class Pin : public iPin
{
//variables
public:
protected:
private:
    ePinId pinId;
    iPinHw * pinHw;

//functions
public:
    Pin(ePinId pinId, iPinHw * pinHw, ePinDir pinDir, ePinState pinState);
    ~Pin();
    void set();
    void reset();
    void toggle();
    void output();
    void input();
    bool isSet();
protected:
private:

}; //Pin

#endif //__PIN_H__
