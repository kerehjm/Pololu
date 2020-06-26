/* 
* Adc.h
*
* Created: 12/05/2020 19:25:24
* Author: Mathew.Kuloba
*/


#ifndef __ADC_H__
#define __ADC_H__

#include <avr/io.h>
#include <stdint.h>
#include "eAdcId.h"

class Adc
{
//variables
public:
protected:
private:

//functions
public:
    static void init();
    static void on();
    static void off();
    static uint8_t read(eAdcId channel);
protected:
private:
    Adc();
    ~Adc();

}; //Adc

#endif //__ADC_H__
