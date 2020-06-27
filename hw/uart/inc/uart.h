/* 
* Uart.h
*
* Created: 12/05/2020 20:27:52
* Author: Mathew.Kuloba
*/


#ifndef __UART_H__
#define __UART_H__

#include <avr/io.h>
#include <avr/interrupt.h>
#include "pinFactory.h"

#define UART_RX_BUFF_SIZE 128

extern "C" void USART_RX_vect(void) __attribute__((interrupt));

class Uart
{
//variables
public:
protected:
private:
    static uint8_t uart_rx_buffer[UART_RX_BUFF_SIZE];
    static uint8_t uart_rx_in_count;
    static iPin *txd;

//functions
public:
	~Uart();
    static void init();
    static void enable();
    static void disable();
    static void write(uint8_t data);
protected:
private:
    friend void USART_RX_vect(void);
    static void rxHandler();
}; //Uart


extern Uart serial;

#endif //__UART_H__
