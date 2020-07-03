/* 
* iDebug.hpp
*
* Created: 23/05/2020 10:58:24
* Author: Mathew.Kuloba
*/


#ifndef __IDEBUG_H__
#define __IDEBUG_H__

enum class eDebugLevel {
    all,
    debug,
    info,
    Error,
    none
};

class iDebug
{
//functions
public:
    ~iDebug(){}
    virtual void write(eDebugLevel level, const char *format, ...) = 0;
    virtual void setLevel(eDebugLevel level) = 0;
protected:
private:

}; //iDebug

#endif //__IDEBUG_H__
