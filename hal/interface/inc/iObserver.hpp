#ifndef __IOBSERVER_H__
#define __IOBSERVER_H__

class iObserver
{
//functions
public:
    virtual ~iObserver(){}
    virtual void update(bool isPressed) = 0;
};

#endif //__IOBSERVER_H__