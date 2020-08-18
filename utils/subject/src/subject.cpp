#include <stdint.h> 
#include "iObserver.hpp"
#include "iSubject.hpp"
#include "subject.hpp"

Subject::Subject()
{

}

Subject::~Subject()
{
    
}

bool Subject::add(iObserver* observer)
{
    bool result = false;
    
    if(!observerExists(observer))
    {
        for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
        {
            if(nullptr == observers[i]) //empty slot
            {
                observers[i] = observer; //add observer
                result = true;
                break;
            }
        }
    }
    return result;
}

void Subject::remove(iObserver* observer)
{
    for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
    {
        if(observer == observers[i]) //observer found
        {
            observers[i] = nullptr; //remove observer
            break;
        }
    }
}

void Subject::notify()
{
    notifyObservers(this, nullptr);
}

void Subject::notify(const void * arg)
{
    notifyObservers(this, arg);
}

bool Subject::observerExists(iObserver* observer)
{
    bool result = false;
    for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
    {
        if(observer == observers[i])
        {
            result = true;
            break;
        }
    }
    return result;
}

void Subject::notifyObservers(iSubject * subject, const void * arg)
{
    for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
    {
        if(nullptr != observers[i]) //observer registered
        {
            observers[i]->update(this, arg);
        }
    }
}