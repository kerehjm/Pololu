/* 
* iButtonHw.hp
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __IINTERRUPT_H__
#define __IINTERRUPT_H__

class iInterrupt
{
//functions
public:
    virtual ~iInterrupt(){}
    virtual void isr(const void *) = 0;
}; //iInterrupt

#endif //__IINTERRUPT_H__
