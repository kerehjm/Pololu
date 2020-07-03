/* 
* iMotor.h
*
* Created: 23/05/2020 10:46:54
* Author: Mathew.Kuloba
*/


#ifndef __IMOTOR_H__
#define __IMOTOR_H__

enum class eMotorId
{
    motor_1,
    motor_2
}; //eMotorId

class iMotor
{
//functions
public:
	virtual ~iMotor(){}
    virtual void off() = 0;
    virtual void forward(uint8_t speed) = 0;
    virtual void reverse(uint8_t speed) = 0;
    virtual void brake() = 0;

}; //iMotor

#endif //__IMOTOR_H__
