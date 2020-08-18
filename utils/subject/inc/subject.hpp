#ifndef __SUBJECT_H__
#define __SUBJECT_H__

class Subject : public iSubject
{
//variables
public:
protected:
private:
    static const uint8_t MAX_NO_OF_OBSERVERS = 10;
    iObserver* observers[MAX_NO_OF_OBSERVERS] = {}; // observers

//functions
public:
    static iSubject * create();
    Subject();
    ~Subject();
    bool add(iObserver * observer) override;
    void remove(iObserver * observer) override;
    void notify() override;
    void notify(const void * arg) override;
protected:
private:
    bool observerExists(iObserver* observer);
    void notifyObservers(iSubject * subject, const void * arg);

}; //Observer

#endif //__SUBJECT_H__
