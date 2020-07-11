/* 
* iTimer.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __IUART_H__
#define __IUART_H__

#include <stdint.h>

class iUart
{
//functions
public:
    virtual ~iUart(){}
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual void write(uint8_t data) = 0;
}; //iUart

#endif //__IUART_H__
