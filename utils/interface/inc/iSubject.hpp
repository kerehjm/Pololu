#ifndef __ISUBJECT_H__
#define __ISUBJECT_H__

class iSubject
{
//functions
public:
    virtual ~iSubject(){}
    virtual bool add(iObserver * observer) = 0;
    virtual void remove(iObserver * observer) = 0;
    virtual void notify() = 0;
    virtual void notify(const void * arg) = 0;
};

#endif //__ISUBJECT_H__