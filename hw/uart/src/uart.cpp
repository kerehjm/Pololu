/* 
* Uart.cpp
*
* Created: 12/05/2020 20:27:52
* Author: Mathew.Kuloba
*/

#include "uart.hpp"

// iPin *Uart::txd;

ISR(USART_RX_vect)
{
    //Check for errors
    if ((UCSR0A & (1 << FE0)) || (UCSR0A & (1 << DOR0)) || (UCSR0A & (1 << UPE0)))
    {
        //Flush rx buffer
        while (UCSR0A & (1 << RXC0))
        {
            UDR0; //read
        }            
        return;
    }
    
    //serial.rxHandler();
}

void Uart::create()
{
    
}

void Uart::init()
{
    //Set baud rate
    UBRR0H = 0;
    UBRR0L = 129;

    //Select frame format
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); //Select 8 data bits in a frame

    //Enable tx/rx
    UCSR0B |= (1 << RXEN0); //Enable rx
    UCSR0B |= (1 << TXEN0); //Enable tx

    //Enable rx int
    UCSR0B |= (1 << RXCIE0); //Enable rx int
    
    sei(); //enable global ints
    
    // Uart::txd = PinFactory::create(ePinId::PD1_UART0_TXD);
    
    enable();
} //Uart

// default destructor
Uart::~Uart()
{
} //~Uart

void Uart::write(uint8_t data)
{
    //Send a byte
    while (!(UCSR0A & (1 << UDRE0)));           //Wait tx buffer to empty
    UDR0 = data; //Load tx buffer
    while (!(UCSR0A & (1 << UDRE0))); //Wait for last byte to go
}

//Turn on uart
void Uart::enable()
{
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0); //Enable tx and TX
    // txd->output();
    // txd->set();
}

//Turn off uart
void Uart::disable()
{
    UCSR0B &= ~((1 << TXEN0) | (1 << RXEN0)); //Disable tx, rx
}

void Uart::rxHandler()
{
    //Uart::uart_rx_buffer[Uart::uart_rx_in_count] = UDR0; //Read byte clears RXC0 flag
    //if (Uart::uart_rx_in_count == UART_RX_BUFF_SIZE)
    //{
    //Uart::uart_rx_in_count = 0;
    //}
    //if (Uart::uart_rx_buffer[Uart::uart_rx_in_count] == 0x0A)
    //{
        //Uart::uart_rx_in_count = 0;
    //}
    //Uart::uart_rx_in_count++;
}

