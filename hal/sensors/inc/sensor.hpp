/* 
* Sensor.h
*
* Created: 21/05/2020 18:09:37
* Author: Mathew.Kuloba
*/


#ifndef __SENSOR_H__
#define __SENSOR_H__

class Sensor : public iSensor
{
//variables
public:
protected:
    iPin *power;
    iPin *sensor;
    iTimer<uint16_t> *timer;
private:

//functions
public:
    Sensor();
    ~Sensor();
    uint8_t read();
    void charge();
    void discharge();

protected:
private:
    Sensor(const Sensor &c);
    Sensor &operator=(const Sensor &c);

}; //Sensor

#endif //__SENSOR_H__
