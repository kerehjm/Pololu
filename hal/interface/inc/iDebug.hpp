/* 
* iDebug.hpp
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/


#ifndef __IDEBUG_H__
#define __IDEBUG_H__

enum class eDebugLevel {
    none,
    Error,
    info,
    debug,
    all
};

class iDebug
{
//functions
public:
    ~iDebug(){}
    static void init(eDebugLevel level);
    static void setLevel(eDebugLevel level);
    static void error(const char *format, ...);
    static void debug(const char *format, ...);
    static void info(const char *format, ...);
protected:
private:

}; //iDebug

#endif //__IDEBUG_H__
