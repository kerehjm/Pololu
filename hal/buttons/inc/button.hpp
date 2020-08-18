/* 
* Button.h
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/


#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button : public iButton, public Subject
{
//variables
public:
protected:
private:
    iPinHw * buttonPinHw;
    iInterrupt * buttonInt;

//functions
public:
    static iButton * create(eButtonId buttonId);
    Button(iPinHw * buttonPinHw, iInterrupt* interrupt);
    ~Button() override;
    bool isPressed() override;
protected:
private:
}; //Button

#endif //__BUTTON_H__
