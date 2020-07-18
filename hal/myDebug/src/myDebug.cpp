/* 
* Debug.cpp
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "iUart.hpp"
#include "iDebug.hpp"
#include "myDebug.hpp"

Debug::Debug(iUart *uart, eDebugLevel level)
{
    this->uart = uart;
    this->debugLevel = level;
    uart->enable();
}

Debug::~Debug()
{
}

void Debug::log(eDebugLevel level, const char *format, ...)
{
    if (this->debugLevel >= level)
    {
        //cli();
        char buffer[256];
        va_list args;
        va_start (args, format);
        memset(buffer, '\0', sizeof(buffer));
        vsnprintf (buffer, sizeof(buffer), format, args);
        
        //print buffer
        //--------------
        int i =0;
        while (buffer[i] != '\0')
        {
            uart->write(buffer[i++]);
        }
        uart->write('\n');
        //--------------
        
        va_end (args);
        
        //sei();
    }
}
