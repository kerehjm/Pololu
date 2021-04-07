#ifndef ILCDHW_H_
#define ILCDHW_H_

class iLcdHw
{
public:
    static iLcdHw * create();
    virtual ~iLcdHw() {}
    virtual void write_data(uint8_t data) = 0;
    virtual void clear_display() = 0;
};

#endif