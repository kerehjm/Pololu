#ifndef ILCD_H_
#define ILCD_H_

class iLcd
{
public:
    static iLcd * create();
    virtual ~iLcd() {}
    virtual void write(uint8_t * data) = 0;
};

#endif /* ILCD_H_ */