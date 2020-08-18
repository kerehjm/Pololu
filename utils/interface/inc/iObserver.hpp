#ifndef __IOBSERVER_H__
#define __IOBSERVER_H__

class iSubject;

class iObserver
{
//functions
public:
    virtual ~iObserver(){}
    virtual void update(iSubject * subject, const void *) = 0;
};

#endif //__IOBSERVER_H__