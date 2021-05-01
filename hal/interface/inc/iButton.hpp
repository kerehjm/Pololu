#ifndef __IBUTTON_H__
#define __IBUTTON_H__

enum class eButtonId
{
    a,
    b,
    c
}; //eButtonId

class iButton
{
//functions
public:
    static iButton * create(eButtonId buttonId, void (*callback)(void));
    virtual ~iButton(){}
    virtual bool isPressed() = 0;
}; //iButton

#endif //__IBUTTON_H__
