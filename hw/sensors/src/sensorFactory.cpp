/* 
* SensorFactory.cpp
*
* Created: 16/05/2020 12:24:07
* Author: Mathew.Kuloba
*/


#include "sensorFactory.h"

iSensor *SensorFactory::create(eSensorId sensor_id)
{
    iSensor *sensor;
    iPin *pin = nullptr;
    iPin *pwr = PinFactory::create(ePinId::PC5_SENSOR_POWER);
    iTimer *tmr = TimerFactory::create(eTimerId::tmr1, nullptr);
    switch (sensor_id)
    {
        case eSensorId::prx:
            pin = PinFactory::create(ePinId::PD2_LCD_RS);    
            break;
        case eSensorId::rl0:
            pin = PinFactory::create(ePinId::PC0_SENSOR0);
            break;
        case eSensorId::rl1:
            pin = PinFactory::create(ePinId::PC1_SENSOR1);
            break;
        case eSensorId::rl2:
            pin = PinFactory::create(ePinId::PC2_SENSOR2);
            break;
        case eSensorId::rl3:
            pin = PinFactory::create(ePinId::PC3_SENSOR3);
            break;
        case eSensorId::rl4:
            pin = PinFactory::create(ePinId::PC4_SENSOR4);
            break;
    }
    
    if (sensor_id == eSensorId::prx)
    {
        sensor = new ProximitySensor(pin, pwr, tmr);
    }
    else
    {
        sensor = new ReflectanceSensor(pin, pwr, tmr);
    }
    return sensor;
}
