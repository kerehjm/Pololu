#include "iUart.hpp"
#include "uart.hpp"

iUart * iUart::create()
{
    return new Uart();
}