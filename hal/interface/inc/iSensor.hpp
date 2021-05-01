/* 
* iSensor.h
*
* Created: 18/05/2020 18:31:16
* Author: Mathew.Kuloba
*/


#ifndef __ISENSOR_H__
#define __ISENSOR_H__

typedef struct _SensorData
{
    uint8_t size;
    uint16_t * readings;

    _SensorData(uint8_t size, uint16_t * readings)
    {
        this->size = size;
        this->readings = readings;
    }
} SensorData;

class iSensor
{
//functions
public:
    static iSensor * createReflectance(iTimer<uint16_t> * timer);
    virtual ~iSensor(){}
    virtual SensorData read() = 0;
}; //iSensor

#endif //__ISENSOR_H__
