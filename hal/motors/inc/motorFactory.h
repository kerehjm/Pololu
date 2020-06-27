/* 
* MotorFactory.h
*
* Created: 15/05/2020 21:45:23
* Author: Mathew.Kuloba
*/


#ifndef __MOTORFACTORY_H__
#define __MOTORFACTORY_H__

#include "iMotor.h"
#include "motor.h"
#include "eMotorId.h"
#include "timer0.h"
#include "timer1.h"
#include "timer2.h"
#include "pinFactory.h"

class MotorFactory
{
//variables
public:
protected:
private:

//functions
public:
    static iMotor *create(eMotorId motor_id);
protected:
private:
    MotorFactory();
    ~MotorFactory();

}; //MotorFactory

#endif //__MOTORFACTORY_H__
