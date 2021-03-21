#ifndef __PWM_H__
#define __PWM_H__

class Pwm : public iPwm
{
//variables
public:
protected:
private:
    iTimerHw<uint8_t> * timerHw;

//functions
public:
    Pwm(iTimerHw<uint8_t> * timerHw);
    ~Pwm();
    void start();
    void startInverted();
    void stop();
    void setDutyCycle(ePwmChannel channel, uint8_t dutyCycle);
    void selectChannel(ePwmChannel channel);
protected:
private:

}; //Pwm

#endif //__PWM_H__
