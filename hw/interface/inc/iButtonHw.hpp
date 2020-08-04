/* 
* iButtonHw.hp
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __IBUTTONHW_H__
#define __IBUTTONHW_H__

enum class eHwButtonId
{
    a,
    b,
    c
}; //eHwButtonId

class iButtonHw
{
//functions
public:
    static iButtonHw * create(eHwButtonId hwButtonId);
    virtual ~iButtonHw(){}
    virtual bool isPressed() = 0;
}; //iButtonHw

#endif //__IBUTTONHW_H__
