/* 
* timer.cpp
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include "iTimer.hpp"
#include "iTimerHw.hpp"
#include "timer.hpp"

// default constructor
template <class T>
Timer<T>::Timer(iTimerHw<T> * timerHw)
{
    this->timerHw = timerHw;
}

// default destructor
template <class T>
Timer<T>::~Timer()
{
    delete(timerHw);
} //~Timer

template <class T>
void Timer<T>::start()
{
    timerHw->start();
}

template <class T>
void Timer<T>::stop()
{
    timerHw->stop();
}

template <class T>
void Timer<T>::setFrequency(T frequency)
{
    timerHw->setTop(frequency);
}

template <class T>
void Timer<T>::setDutyCycle(T dutyCycle)
{
    timerHw->setReload(dutyCycle);
}

template <class T>
T Timer<T>::getCount()
{
    return timerHw->getCount();
}

template class Timer<uint8_t>;
template class Timer<uint16_t>;
