/* 
* iPinHw.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __IPINHW_H__
#define __IPINHW_H__

enum class eHwPinId
{
    PB0_LCD_RW,
    PB1_LCD_DB4,
    PB2_BUZZER,
    PB3_MOTOR2_DIRECTION,
    PB4_LCD_DB5,
    PB5_LCD_DB6,
    PB6_XTAL1,
    PB7_XTAL2,
    PC0_SENSOR0,
    PC1_SENSOR1,
    PC2_SENSOR2,
    PC3_SENSOR3,
    PC4_SENSOR4,
    PC5_SENSOR_POWER,
    PC6_RESET,
    PD0_UART0_RXD,
    PD1_UART0_TXD,
    PD2_LCD_RS,
    PD3_MOTOR2_SPEED,
    PD4_LCD_ENABLE,
    PD5_MOTOR1_SPEED,
    PD6_MOTOR1_DIRECTION,
    PD7_LCD_DB7,
}; //eHwPinId

class iPinHw
{
//functions
public:
    virtual ~iPinHw(){}
    virtual void init(eHwPinId pinId) = 0;
    virtual void set(eHwPinId pinId) = 0;
    virtual void reset(eHwPinId pinId) = 0;
    virtual void toggle(eHwPinId pinId) = 0;
    virtual void output(eHwPinId pinId) = 0;
    virtual void input(eHwPinId pinId) = 0;
    virtual bool is_pin_set(eHwPinId pinId) = 0;
}; //iPinHw

#endif //__IPINHW_H__
