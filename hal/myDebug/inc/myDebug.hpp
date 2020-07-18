/* 
* Debug.h
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/


#ifndef __DEBUG_H__
#define __DEBUG_H__

class Debug : public iDebug
{
//variables
public:
protected:
    void checkInit();
    void init();
private:
    eDebugLevel debugLevel;
    iUart * uart;

//functions
public:
    Debug(iUart * uart, eDebugLevel level);
    ~Debug();
    void log(eDebugLevel level, const char *format, ...);
protected:
private:

}; //Debug

#endif //__DEBUG_H__
