#ifndef ILCD_H_
#define ILCD_H_

class iLcd
{
public:
    static iLcd * create();
    virtual ~iLcd() {}
    virtual void write(const char * data) = 0;
    virtual void print(const char *format, ...) = 0;
};

#endif /* ILCD_H_ */