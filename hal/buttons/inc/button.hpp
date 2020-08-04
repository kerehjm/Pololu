/* 
* Button.h
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/


#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button : public iButton, public iSubject
{
//variables
public:
protected:
private:
    static const uint8_t MAX_NO_OF_OBSERVERS = 10;
    eButtonId buttonId;
    iButtonHw * buttonHw;
    iObserver* observers[MAX_NO_OF_OBSERVERS] = {}; // observers

//functions
public:
    Button(eButtonId buttonId, iButtonHw * buttonHw);
    ~Button();
    bool isPressed() override;
    bool add(iObserver * observer) override;
    void remove(iObserver * observer) override;
    void notify() override;
protected:
private:
    bool observerExists(iObserver* observer);

}; //Button

#endif //__BUTTON_H__
