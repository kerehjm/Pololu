/* 
* PinFactory.h
*
* Created: 16/05/2020 00:36:26
* Author: Mathew.Kuloba
*/


#ifndef __PINFACTORY_H__
#define __PINFACTORY_H__

#include "pin.h"
#include "ePinId.h"

class PinFactory
{
//variables
public:
protected:
private:

//functions
public:
	static iPin *create(ePinId pin_id);
    static Pin createPin(ePinId pinId);
    
protected:
private:
    PinFactory();
    ~PinFactory();

}; //PinFactory

#endif //__PINFACTORY_H__
