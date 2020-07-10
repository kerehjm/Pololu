//
// Created by Mathew Kere on 08/07/2020.
//

#include <avr/io.h>
#include "iPinHw.hpp"
#include "pinPortMap.hpp"
#include "pinHw.hpp"

iPinHw * iPinHw::create(eHwPinId hwPinId)
{
    iPinHw * pinHw = nullptr;

    switch (hwPinId)
    {
    case eHwPinId::PB0_LCD_RW             : pinHw = new PinHw( new PinPortMap(PB0, &PORTB, &DDRB) ); break;
    case eHwPinId::PB1_LCD_DB4            : pinHw = new PinHw( new PinPortMap(PB1, &PORTB, &DDRB) ); break;
    case eHwPinId::PB2_BUZZER             : pinHw = new PinHw( new PinPortMap(PB2, &PORTB, &DDRB) ); break;
    case eHwPinId::PB3_MOTOR2_DIRECTION   : pinHw = new PinHw( new PinPortMap(PB3, &PORTB, &DDRB) ); break;
    case eHwPinId::PB4_LCD_DB5            : pinHw = new PinHw( new PinPortMap(PB4, &PORTB, &DDRB) ); break;
    case eHwPinId::PB5_LCD_DB6            : pinHw = new PinHw( new PinPortMap(PB5, &PORTB, &DDRB) ); break;
    case eHwPinId::PB6_XTAL1              : pinHw = new PinHw( new PinPortMap(PB6, &PORTB, &DDRB) ); break;
    case eHwPinId::PB7_XTAL2              : pinHw = new PinHw( new PinPortMap(PB7, &PORTB, &DDRB) ); break;
    case eHwPinId::PC0_SENSOR0            : pinHw = new PinHw( new PinPortMap(PC0, &PORTC, &DDRC) ); break;
    case eHwPinId::PC1_SENSOR1            : pinHw = new PinHw( new PinPortMap(PC1, &PORTC, &DDRC) ); break;
    case eHwPinId::PC2_SENSOR2            : pinHw = new PinHw( new PinPortMap(PC2, &PORTC, &DDRC) ); break;
    case eHwPinId::PC3_SENSOR3            : pinHw = new PinHw( new PinPortMap(PC3, &PORTC, &DDRC) ); break;
    case eHwPinId::PC4_SENSOR4            : pinHw = new PinHw( new PinPortMap(PC4, &PORTC, &DDRC) ); break;
    case eHwPinId::PC5_SENSOR_POWER       : pinHw = new PinHw( new PinPortMap(PC5, &PORTC, &DDRC) ); break;
    case eHwPinId::PC6_RESET              : pinHw = new PinHw( new PinPortMap(PC6, &PORTC, &DDRC) ); break;
    case eHwPinId::PD0_UART0_RXD          : pinHw = new PinHw( new PinPortMap(PD0, &PORTD, &DDRD) ); break; //pullup enabled
    case eHwPinId::PD1_UART0_TXD          : pinHw = new PinHw( new PinPortMap(PD1, &PORTD, &DDRD) ); break;
    case eHwPinId::PD2_LCD_RS             : pinHw = new PinHw( new PinPortMap(PD2, &PORTD, &DDRD) ); break;
    case eHwPinId::PD3_MOTOR2_SPEED       : pinHw = new PinHw( new PinPortMap(PD3, &PORTD, &DDRD) ); break;
    case eHwPinId::PD4_LCD_ENABLE         : pinHw = new PinHw( new PinPortMap(PD4, &PORTD, &DDRD) ); break;
    case eHwPinId::PD5_MOTOR1_SPEED       : pinHw = new PinHw( new PinPortMap(PD5, &PORTD, &DDRD) ); break;
    case eHwPinId::PD6_MOTOR1_DIRECTION   : pinHw = new PinHw( new PinPortMap(PD6, &PORTD, &DDRD) ); break;
    case eHwPinId::PD7_LCD_DB7            : pinHw = new PinHw( new PinPortMap(PD7, &PORTD, &DDRD) ); break;
    }
    return pinHw;
}
