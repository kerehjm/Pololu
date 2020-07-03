/* 
* Adc.h
*
* Created: 12/05/2020 19:25:24
* Author: Mathew.Kuloba
*/


#ifndef __ADC_H__
#define __ADC_H__

class Adc : public iAdc
{
//variables
public:
protected:
private:

//functions
public:
    void init();
    void on();
    void off();
    uint8_t read(eAdcId channel);
protected:
private:
    Adc();
    ~Adc();

}; //Adc

#endif //__ADC_H__
