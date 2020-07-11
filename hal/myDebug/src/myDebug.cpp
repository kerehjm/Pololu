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

bool Debug::isInitialised = false;
eDebugLevel Debug::debugLevel = eDebugLevel::none;

Debug::Debug(iUart *uart)
{
    this->uart = uart;
    uart->enable();
}

Debug::~Debug()
{
}

void Debug::write(eDebugLevel level, const char *format, ...)
{
    (void)(level);
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

void Debug::setLevel(eDebugLevel level)
{
    checkInit();
    debugLevel = level;
}

void Debug::checkInit()
{
    if (false == isInitialised)
    {
        uart->enable();
        isInitialised = true;
    }
}

