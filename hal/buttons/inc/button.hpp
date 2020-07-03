/* 
* Button.h
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/


#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button : public iButton
{
//variables
public:
protected:
private:
    eButtonId button;

//functions
public:
    Button(eButtonId button);
    ~Button();
    bool isPressed();
protected:
private:

}; //Button

#endif //__BUTTON_H__
