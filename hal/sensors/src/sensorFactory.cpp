#include <stdint.h>
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iPin.hpp"
#include "reflectanceSensor.hpp"
#include "proximitySensor.hpp"

iSensor * iSensor::createReflectance(eSensorId sensorId, iTimer<uint16_t> * timer)
{
    iPin * sensorPin = nullptr;
    
    switch (sensorId)
    {
    case eSensorId::rl0:
        sensorPin = iPin::create(ePinId::PC0_SENSOR0, ePinDir::OUTPUT, ePinState::LOW);
        break;
    case eSensorId::rl1:
        sensorPin = iPin::create(ePinId::PC1_SENSOR1, ePinDir::OUTPUT, ePinState::LOW);
        break;
    case eSensorId::rl2:
        sensorPin = iPin::create(ePinId::PC2_SENSOR2, ePinDir::OUTPUT, ePinState::LOW);
        break;
    case eSensorId::rl3:
        sensorPin = iPin::create(ePinId::PC3_SENSOR3, ePinDir::OUTPUT, ePinState::LOW);
        break;
    case eSensorId::rl4:
        sensorPin = iPin::create(ePinId::PC4_SENSOR4, ePinDir::OUTPUT, ePinState::LOW);
        break;
    default:
        break;
    }

    iPin * power = iPin::create(ePinId::PC5_SENSOR_POWER, ePinDir::OUTPUT, ePinState::LOW);
    iSensor * sensor = new ReflectanceSensor(
        sensorPin,
        power,
        timer);
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