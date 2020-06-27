/* 
* LedFactory.h
*
* Created: 17/05/2020 11:08:01
* Author: Mathew.Kuloba
*/


#ifndef __LEDFACTORY_H__
#define __LEDFACTORY_H__

#include "led.h"
#include "pinFactory.h"

class LedFactory
{
//variables
public:
protected:
private:

//functions
public:
    static iLed *create(eLedId ledId);
protected:
private:
    LedFactory();
    ~LedFactory();
	LedFactory( const LedFactory &c );
	LedFactory& operator=( const LedFactory &c );

}; //LedFactory

#endif //__LEDFACTORY_H__
