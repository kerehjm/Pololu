#ifndef __IPWM_H__
#define __IPWM_H__

enum class ePwmId
{
    pwm_1,
    pwm_2,
};

enum class ePwmChannel
{
    channel_none,
    channel_1,
    channel_2
};

class iPwm
{
//functions
public:
    virtual ~iPwm(){}
    static iPwm * create(ePwmId pwmId);
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setDutyCycle(ePwmChannel channel, uint8_t dutyCycle) = 0;
    virtual void selectChannel(ePwmChannel channel) = 0;
}; //iPwm

#endif //__IPWM_H__
