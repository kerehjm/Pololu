/* 
* Led.h
*
* Created: 13/05/2020 08:10:13
* Author: Mathew.Kuloba
*/

#ifndef __LED_H__
#define __LED_H__

class Led : public iLed
{
//variables
public:
protected:
private:
    iPin *ledPin;

//functions
public:
    static iLed *create(eLedId ledId);
    Led(iPin *ledPin);
    ~Led();
    void on();
    void off();
    void toggle();
protected:
private:

}; //Led

#endif //__LED_H__
