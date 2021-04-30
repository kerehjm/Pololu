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

eDebugLevel Debug::debugLevel = eDebugLevel::none;
iUart * Debug::uart = nullptr;
static void log(eDebugLevel level, const char *format, va_list args);

void iDebug::init(eDebugLevel level)
{
    Debug::uart = iUart::create();
    Debug::debugLevel = level;
    Debug::uart->enable();
}

void log(eDebugLevel level, const char *format, va_list args)
{
    if ((Debug::debugLevel == eDebugLevel::none) || (Debug::uart == nullptr))
    {
        return;
    }

    if (Debug::debugLevel >= level)
    {
        char buffer[256];
        
        memset(buffer, '\0', sizeof(buffer));
        vsnprintf (buffer, sizeof(buffer), format, args);

        int i =0;
        while (buffer[i] != '\0')
        {
            Debug::uart->write(buffer[i++]);
        }
        Debug::uart->write('\r');
        Debug::uart->write('\n');
    }
}

void iDebug::error(const char *format, ...)
{
    va_list args;
    va_start (args, format);
    log(eDebugLevel::Error, format, args);
    va_end (args);
}

void iDebug::debug(const char *format, ...)
{
    va_list args;
    va_start (args, format);
    log(eDebugLevel::debug, format, args);
    va_end (args);
}

void iDebug::info(const char *format, ...)
{
    va_list args;
    va_start (args, format);
    log(eDebugLevel::info, format, args);
    va_end (args);
}
