/* 
* Motor.h
*
* Created: 15/05/2020 20:43:36
* Author: Mathew.Kuloba
*/


#ifndef __MOTOR_H__
#define __MOTOR_H__

class Motor : public iMotor
{
//variables
public:
protected:
private:
    iPin *direction;
    iPin *speed;
    iTimer *timer;
    eMotorId motorId;
    iDebug * debug;

//functions
public:
    Motor();
	~Motor();
    Motor(eMotorId motorId, iTimer *timer, iPin *direction, iPin *speed);
    Motor(eMotorId motorId, iTimer *timer, iPin *direction, iPin *speed, iDebug* debug);
    void off();
    void forward(uint8_t speed);
    void reverse(uint8_t speed);
    void brake();
protected:
private:

}; //Motor

#endif //__MOTOR_H__
