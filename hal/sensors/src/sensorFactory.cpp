#include <stdint.h>
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iPin.hpp"
#include "reflectanceSensor.hpp"
#include "proximitySensor.hpp"

iSensor * iSensor::createReflectance(iTimer<uint16_t> * timer)
{
    static const uint8_t COUNT = 5;
    static uint8_t readings[COUNT];
    iPin * sensorPin[COUNT] = {};
    sensorPin[0] = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::HIGH);
    sensorPin[1] = iPin::create(ePinId::PC1_SENSOR1, ePinDir::OUTPUT, ePinState::HIGH);
    sensorPin[2] = iPin::create(ePinId::PC2_SENSOR2, ePinDir::OUTPUT, ePinState::HIGH);
    sensorPin[3] = iPin::create(ePinId::PC3_SENSOR3, ePinDir::OUTPUT, ePinState::HIGH);
    sensorPin[4] = iPin::create(ePinId::PC4_SENSOR4, ePinDir::OUTPUT, ePinState::HIGH);

    iPin * power = iPin::create(ePinId::PC5_SENSOR_POWER, ePinDir::OUTPUT, ePinState::LOW);
    iSensor * sensor = new ReflectanceSensor(
        sensorPin,
        COUNT,
        power,
        timer,
        readings);
    return sensor;
}

iSensor * iSensor::createProximity(iTimer<uint16_t> * timer)
{
    iPin * sensorPin = iPin::create(ePinId::PD1_UART0_TXD, ePinDir::OUTPUT, ePinState::LOW);

    iSensor * sensor = new ProximitySensor(
        sensorPin,
        nullptr,
        timer);
    return sensor;
}