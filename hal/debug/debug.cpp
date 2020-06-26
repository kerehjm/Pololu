/* 
* Debug.cpp
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/


#include "debug.h"

bool Debug::isInitialised = false;
eDebugLevel Debug::debugLevel = eDebugLevel::none;

void Debug::init()
{
    Uart::init();
    //setLevel(eDebugLevel::all);
}

void Debug::write(eDebugLevel level, const char *format, ...)
{
    cli();
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
        Uart::write(buffer[i++]);
    }
    Uart::write('\n');
    //--------------
    
    va_end (args);
    
    sei();
}

void Debug::setLevel(eDebugLevel level)
{
    checkInit();
    debugLevel = level;
    isInitialised = true;
}

void Debug::checkInit()
{
    if (false == isInitialised)
    {
        init();
    }
}

