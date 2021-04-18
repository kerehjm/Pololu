#include <stdint.h>
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iPin.hpp"
#include "reflectanceSensor.hpp"
#include "proximitySensor.hpp"
#include "iDebug.hpp"

iSensor * iSensor::createReflectance(iTimer<uint16_t> * timer)
{
    iSensor * sensor = nullptr;
    if (timer != nullptr)
    {
        static const uint8_t COUNT = 5;
        static uint8_t readings[COUNT];
        static iPin * sensorPin[COUNT] = {};
        sensorPin[0] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[1] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[2] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[3] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);
        sensorPin[4] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);

        iPin * power = iPin::create(ePinId::PC5_SENSOR_POWER, ePinDir::OUTPUT, ePinState::LOW);
        sensor = new ReflectanceSensor(
            sensorPin,
            COUNT,
            power,
            timer,
            readings);
    }
    return sensor;
}

iSensor * iSensor::createProximity(iTimer<uint16_t> * timer)
{
    iSensor * sensor = nullptr;
    if (timer != nullptr)
    {
        iPin * sensorPin = iPin::create(ePinId::PD1_UART0_TXD, ePinDir::OUTPUT, ePinState::LOW);

        sensor = new ProximitySensor(
            sensorPin,
            nullptr,
            timer);
    }
    return sensor;
}