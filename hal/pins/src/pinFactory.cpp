//
// Created by Mathew Kere on 08/07/2020.
//

#include <stdint.h>
#include "iPinHw.hpp"
#include "iPin.hpp"
#include "pin.hpp"

iPin * iPin::create(ePinId pinId, ePinDir pinDir, ePinState pinState) 
{
    iPin * pin = nullptr;
    iPinHw * pinHw = nullptr;

#ifndef GOOGLE_TEST // unit tests dont like static functions called in a static functions because they cant be mocked
    switch (pinId)
    {
        case ePinId::PB0_LCD_RW             : pinHw = iPinHw::create( eHwPinId::PB0_LCD_RW          ); break;
        case ePinId::PB1_LCD_DB4            : pinHw = iPinHw::create( eHwPinId::PB1_LCD_DB4         ); break;
        case ePinId::PB2_BUZZER             : pinHw = iPinHw::create( eHwPinId::PB2_BUZZER          ); break;
        case ePinId::PB3_MOTOR2_DIRECTION   : pinHw = iPinHw::create( eHwPinId::PB3_MOTOR2_DIRECTION); break;
        case ePinId::PB4_LCD_DB5            : pinHw = iPinHw::create( eHwPinId::PB4_LCD_DB5         ); break;
        case ePinId::PB5_LCD_DB6            : pinHw = iPinHw::create( eHwPinId::PB5_LCD_DB6         ); break;
        case ePinId::PB6_XTAL1              : pinHw = iPinHw::create( eHwPinId::PB6_XTAL1           ); break;
        case ePinId::PB7_XTAL2              : pinHw = iPinHw::create( eHwPinId::PB7_XTAL2           ); break;
        case ePinId::PC0_SENSOR0            : pinHw = iPinHw::create( eHwPinId::PC0_SENSOR0         ); break;
        case ePinId::PC1_SENSOR1            : pinHw = iPinHw::create( eHwPinId::PC1_SENSOR1         ); break;
        case ePinId::PC2_SENSOR2            : pinHw = iPinHw::create( eHwPinId::PC2_SENSOR2         ); break;
        case ePinId::PC3_SENSOR3            : pinHw = iPinHw::create( eHwPinId::PC3_SENSOR3         ); break;
        case ePinId::PC4_SENSOR4            : pinHw = iPinHw::create( eHwPinId::PC4_SENSOR4         ); break;
        case ePinId::PC5_SENSOR_POWER       : pinHw = iPinHw::create( eHwPinId::PC5_SENSOR_POWER    ); break;
        case ePinId::PC6_RESET              : pinHw = iPinHw::create( eHwPinId::PC6_RESET           ); break;
        case ePinId::PD0_UART0_RXD          : pinHw = iPinHw::create( eHwPinId::PD0_UART0_RXD       ); break;
        case ePinId::PD1_UART0_TXD          : pinHw = iPinHw::create( eHwPinId::PD1_UART0_TXD       ); break;
        case ePinId::PD1_RED_LED            : pinHw = iPinHw::create( eHwPinId::PD1_UART0_TXD       ); break;
        case ePinId::PD2_LCD_RS             : pinHw = iPinHw::create( eHwPinId::PD2_LCD_RS          ); break;
        case ePinId::PD3_MOTOR2_SPEED       : pinHw = iPinHw::create( eHwPinId::PD3_MOTOR2_SPEED    ); break;
        case ePinId::PD4_LCD_ENABLE         : pinHw = iPinHw::create( eHwPinId::PD4_LCD_ENABLE      ); break;
        case ePinId::PD5_MOTOR1_SPEED       : pinHw = iPinHw::create( eHwPinId::PD5_MOTOR1_SPEED    ); break;
        case ePinId::PD6_MOTOR1_DIRECTION   : pinHw = iPinHw::create( eHwPinId::PD6_MOTOR1_DIRECTION); break;
        case ePinId::PD7_LCD_DB7            : pinHw = iPinHw::create( eHwPinId::PD7_LCD_DB7         ); break;
        case ePinId::PD7_GREEN_LED          : pinHw = iPinHw::create( eHwPinId::PD7_LCD_DB7         ); break;
    }
#endif
    pin = new Pin(pinId, pinHw, pinDir, pinState);
    return pin;
}
