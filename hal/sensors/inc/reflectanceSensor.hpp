/* 
* ReflectanceSensor.h
*
* Created: 16/05/2020 10:48:22
* Author: Mathew.Kuloba
*/


#ifndef __REFLECTANCESENSOR_H__
#define __REFLECTANCESENSOR_H__

class ReflectanceSensor : public Sensor
{
//variables
public:
protected:
private:

//functions
public:
	ReflectanceSensor();
	~ReflectanceSensor();
    ReflectanceSensor(iPin *sensor, iPin *power, iTimer *timer);
    uint8_t read();
protected:
    void charge();
    void discharge();
private:
	ReflectanceSensor( const ReflectanceSensor &c );
	ReflectanceSensor& operator=( const ReflectanceSensor &c );

}; //ReflectanceSensor

#endif //__REFLECTANCESENSOR_H__
