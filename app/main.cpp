/*
 * Pololu.cpp
 *
 * Created: 12/05/2020 15:05:10
 * Author : Mathew.Kuloba
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "iPin.hpp"
#include "iLed.hpp"
#include "iMotor.hpp"
#include "iSensor.hpp"
#include "iButton.hpp"
#include "iTimer.hpp"
#include "iDebug.hpp"
#include <util/delay.h>

void * operator new(size_t size);
void operator delete(void * ptr);

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);

extern "C" void __cxa_pure_virtual(void);

void * operator new(size_t size)
{
    return malloc(size);
}

void operator delete(void * ptr)
{
    free(ptr);
}

void operator delete(void* ptr, unsigned int size)
{
    (void)(size);
    free(ptr);
}

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void timer1_ctc_2hz(void)
{
    // set up timer with prescaler = 64 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS12);
  
    // initialize counter
    TCNT1 = 0;
  
    // initialize compare value
    OCR1A = 19530;
  
    // enable compare interrupt
    TIMSK1 |= (1 << OCIE1A);
  
    // enable global interrupts
    sei();
}

void pwm_init()
{
    TCCR2A |= (1<<WGM20)|(1<<COM2A1)|(1<<COM2A1);
    TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22);

    DDRB |= (1<<PB3);

    OCR2A = 50;

    TCCR0A |= (1<<WGM00)|(1<<COM0A1)|(1<<WGM01);
    TCCR0B |= (1<<CS00) | (1<<CS02);

    DDRD |= (1<<PD6);

    OCR0A = 50;
}

void time(void);

iLed * led;
iDebug * debugg;
iMotor * motor_1;
iMotor * motor_2;

int main()
{
    static const uint8_t speed = 30;
    static const uint8_t direction = 4;
    // led = iLed::create(eLedId::red);
    // led->on();

    motor_1 = iMotor::create(eMotorId::motor_1);
    motor_2 = iMotor::create(eMotorId::motor_2);

    if (direction == 0)
    {
        motor_1->forward(speed);
        motor_2->forward(speed);
    }
    else if(direction == 1)
    {
        motor_1->reverse(speed);
        motor_2->reverse(speed);
    }
    else
    {

    }


    // iPin::create(ePinId::PD6_MOTOR1_DIRECTION, ePinDir::OUTPUT, ePinState::LOW);
    // iPin::create(ePinId::PD5_MOTOR1_SPEED, ePinDir::OUTPUT, ePinState::LOW);
    // iPin::create(ePinId::PB3_MOTOR2_DIRECTION, ePinDir::OUTPUT, ePinState::LOW);
    // iPin::create(ePinId::PD3_MOTOR2_SPEED, ePinDir::OUTPUT, ePinState::LOW);

    while (1)
    {
        
    }
}


void time(void)
{
    led->toggle();
    // debugg->log(eDebugLevel::debug, "motor [%d] off", 1);
}
