/* 
* Adc.cpp
*
* Created: 12/05/2020 19:25:24
* Author: Mathew.Kuloba
*/

#include "adc.hpp"

// default constructor
Adc::Adc()
{
} //Adc

// default destructor
Adc::~Adc()
{
} //~Adc

void Adc::init()
{
    //Reference selection
    ADMUX |= ( 1 << REFS0 ); //AVcc with external capacitor at AREF pin
    
    //Select pre-scaler 128
    ADCSRA |= ( 1 << ADPS0 )|( 1 << ADPS1 )|( 1 << ADPS2 ); //128
    
    Adc::on(); //Turn on clock and enable adc
}

//Shut down the adc
void Adc::off() //Turn off adc b4 shurt down
{
    //Disable ADC
    ADCSRA &= ~( 1 << ADEN );
    
    //Turn off adc to save power
    PRR |= ( 1 << PRADC ); //Disables adc clock
}

//Turn on the adc
void Adc::on()
{
    //Turn on adc
    PRR &= ~( 1 << PRADC ); //Enables adc clock

    //Enable ADC
    ADCSRA |= ( 1 << ADEN );
}

//Get adc reading
uint8_t Adc::read(eAdcId channel)
{
    uint8_t reading = 0;
    
    //Select adc channel b4 starting conversion
    ADMUX = (ADMUX & 0b11111000) | channel; //Select channel
    
    //Start first conversion
    ADCSRA |= (1 << ADSC); //High to start conversion bit
    while( ADCSRA & (1 << ADSC) ); //Wait for conversion to complete
    reading = ADCW;
    
    //adc_turnoff(); //Turn off to save power
    
    return reading;
}