/* 
* Debug.h
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/


#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "uart.h"
#include <stdio.h>
#include <string.h>

enum class eDebugLevel {
    all, debug, info, Error, none
};

class Debug
{
//variables
public:
protected:
    static void checkInit();
    static void init();
private:
    static bool isInitialised;
    static eDebugLevel debugLevel;
    

//functions
public:
    static void write(eDebugLevel level, const char *format, ...);
    static void setLevel(eDebugLevel level);
protected:
private:
    Debug();

}; //Debug

#endif //__DEBUG_H__
