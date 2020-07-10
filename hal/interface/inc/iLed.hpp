/* 
* iLed.h
*
* Created: 08/06/2020 16:33:54
* Author: Mathew.Kuloba
*/


#ifndef __ILED_H__
#define __ILED_H__

enum class eLedId
{
    green,
    red
}; //eLedId

class iLed
{
//functions
public:
    static iLed * create(eLedId ledId);
    virtual ~iLed(){}
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;

}; //iLed

#endif //__ILED_H__
