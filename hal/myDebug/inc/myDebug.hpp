/* 
* Debug.h
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/


#ifndef __DEBUG_H__
#define __DEBUG_H__

class Debug
{
//variables
public:
protected:
    void checkInit();
    void init();
private:
    static bool isInitialised;
    static eDebugLevel debugLevel;
    iUart * uart;

//functions
public:
    Debug(iUart * uart);
    ~Debug();
    void write(eDebugLevel level, const char *format, ...);
    void setLevel(eDebugLevel level);
protected:
private:

}; //Debug

#endif //__DEBUG_H__
