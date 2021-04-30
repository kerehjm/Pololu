#include <stdint.h>
#include "iPwm.hpp"
#include "iTimerHw.hpp"
#include "pwm.hpp"

// default constructor
Pwm::Pwm(iTimerHw<uint8_t> * timerHw)
{
    this->timerHw = timerHw;
}

// default destructor
Pwm::~Pwm()
{
    delete(timerHw);
} //~Pwm

void Pwm::start()
{
    timerHw->selectCompareOutputMode(eOutput::A, eoutputCompareMode::setOnCompare);
    timerHw->start();
}

void Pwm::startInverted()
{
    timerHw->selectCompareOutputMode(eOutput::B, eoutputCompareMode::clearClearOnCompare);
    timerHw->start();
}

void Pwm::stop()
{
    timerHw->stop();
}

void Pwm::setDutyCycle(ePwmChannel channel, uint8_t dutyCycle)
{
    switch (channel)
    {
    case ePwmChannel::channel_1:
        timerHw->setTop(dutyCycle);
        break;
    case ePwmChannel::channel_2:
        timerHw->setReload(dutyCycle);
        break;
    default:
        break;
    }
}

void Pwm::selectChannel(ePwmChannel channel)
{
    switch (channel)
    {
    case ePwmChannel::channel_none:
        timerHw->selectCompareOutputMode(eOutput::A, eoutputCompareMode::normalCompare);
        timerHw->selectCompareOutputMode(eOutput::B, eoutputCompareMode::normalCompare);
        break;
    case ePwmChannel::channel_1:
        timerHw->selectCompareOutputMode(eOutput::A, eoutputCompareMode::setOnCompare);
        timerHw->selectCompareOutputMode(eOutput::B, eoutputCompareMode::normalCompare);
        break;
    case ePwmChannel::channel_2:
        timerHw->selectCompareOutputMode(eOutput::A, eoutputCompareMode::normalCompare);
        timerHw->selectCompareOutputMode(eOutput::B, eoutputCompareMode::setOnCompare);
    default:
        break;
    }
}
