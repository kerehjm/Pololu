/* 
* Button.h
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/


#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <avr/io.h>
#include "pinFactory.h"
#include "iButton.h"

class Button : public iButton
{
//variables
public:
protected:
    iPin *pin;
private:

//functions
public:
	Button();
	~Button();
    bool isPressed();
protected:
private:

}; //Button

#endif //__BUTTON_H__
