#include <stdint.h>
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iPin.hpp"
#include "reflectanceSensor.hpp"
#include "iDebug.hpp"

iSensor * iSensor::createReflectance(iTimer<uint16_t> * timer)
{
    iSensor * sensor = nullptr;
    if (timer != nullptr)
    {
        static const uint8_t COUNT = 5;
        static uint16_t readings[COUNT];
        static iPin * sensorPin[COUNT] = {};
        sensorPin[0] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[1] = iPin::create(ePinId::PC1_SENSOR1, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[2] = iPin::create(ePinId::PC2_SENSOR2, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[3] = iPin::create(ePinId::PC3_SENSOR3, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[4] = iPin::create(ePinId::PC4_SENSOR4, ePinDir::OUTPUT, ePinState::HIGH);

        iPin * power = iPin::create(ePinId::PC5_SENSOR_POWER, ePinDir::OUTPUT, ePinState::LOW);
        sensor = new ReflectanceSensor(
            &sensorPin[0],
            COUNT,
            power,
            timer,
            readings);
    }
    return sensor;
}
