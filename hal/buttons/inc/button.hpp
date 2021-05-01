#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button : public iButton
{
//variables
public:
protected:
private:
    iButtonHw * buttonHw;

//functions
public:
    Button(iButtonHw * buttonHw);
    ~Button();
    bool isPressed();
protected:
private:
}; //Button

#endif //__BUTTON_H__
