/* 
* PinHw.cpp
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/

#include "PinHw.hpp"

PinPortMap PinHw::pin;

void PinHw::init(eHwPinId pinId)
{
    // switch (pinId)
    //  {
    //      case eHwPinId::PB0_LCD_RW             : pin = new Pin( PinPortMap(PB0, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB1_LCD_DB4            : pin = new Pin( PinPortMap(PB1, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB2_BUZZER             : pin = new Pin( PinPortMap(PB2, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB3_MOTOR2_DIRECTION   : pin = new Pin( PinPortMap(PB3, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB4_LCD_DB5            : pin = new Pin( PinPortMap(PB4, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB5_LCD_DB6            : pin = new Pin( PinPortMap(PB5, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB6_XTAL1              : pin = new Pin( PinPortMap(PB6, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PB7_XTAL2              : pin = new Pin( PinPortMap(PB7, &PORTB, &DDRB), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC0_SENSOR0            : pin = new Pin( PinPortMap(PC0, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC1_SENSOR1            : pin = new Pin( PinPortMap(PC1, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC2_SENSOR2            : pin = new Pin( PinPortMap(PC2, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC3_SENSOR3            : pin = new Pin( PinPortMap(PC3, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC4_SENSOR4            : pin = new Pin( PinPortMap(PC4, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC5_SENSOR_POWER       : pin = new Pin( PinPortMap(PC5, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PC6_RESET              : pin = new Pin( PinPortMap(PC6, &PORTC, &DDRC), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD0_UART0_RXD          : pin = new Pin( PinPortMap(PD0, &PORTD, &DDRD), ePinDir::INPUT,  ePinState::HIGH); break; //pullup enabled
    //      case eHwPinId::PD1_UART0_TXD          : pin = new Pin( PinPortMap(PD1, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD1_RED_LED            : pin = new Pin( PinPortMap(PD1, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD2_LCD_RS             : pin = new Pin( PinPortMap(PD2, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD3_MOTOR2_SPEED       : pin = new Pin( PinPortMap(PD3, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD4_LCD_ENABLE         : pin = new Pin( PinPortMap(PD4, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD5_MOTOR1_SPEED       : pin = new Pin( PinPortMap(PD5, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD6_MOTOR1_DIRECTION   : pin = new Pin( PinPortMap(PD6, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD7_LCD_DB7            : pin = new Pin( PinPortMap(PD7, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //      case eHwPinId::PD7_GREEN_LED          : pin = new Pin( PinPortMap(PD7, &PORTD, &DDRD), ePinDir::OUTPUT, ePinState::LOW ); break;
    //  }    
}

void PinHw::set(eHwPinId pinId)
{
    *pin.port |= (1 << pin.num);
}

void PinHw::reset(eHwPinId pinId)
{
    *pin.port &= ~(1 << pin.num);
}

void PinHw::toggle(eHwPinId pinId)
{
    *pin.port ^= (1 << pin.num);
}

void PinHw::input(eHwPinId pinId)
{
    *pin.ddr &= ~(1 << pin.num);
}

void PinHw::output(eHwPinId pinId)
{
    *pin.ddr |= (1 << pin.num);
}

bool PinHw::is_pin_set(eHwPinId pinId)
{
    return (*pin.port & (1 << pin.num));
}
