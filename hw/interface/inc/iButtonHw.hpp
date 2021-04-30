#ifndef IBUTTON_HW_H
#define IBUTTON_HW_H

enum class eButtonHwId
{
    a,
    b,
    c
};

class iButtonHw
{
public:
    static iButtonHw * create(eButtonHwId buttonHwId, void(*callback)(void));
    virtual ~iButtonHw() {}
    virtual bool is_pressed(void) = 0;
};

#endif