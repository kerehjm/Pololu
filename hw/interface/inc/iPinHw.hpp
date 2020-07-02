/* 
* iPinHw.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __IPINHW_H__
#define __IPINHW_H__

#include <stdint.h>
#include "ePinId.hpp"

class iPinHw
{
//functions
public:
    virtual ~iPinHw(){}
    virtual void init(ePinId pinId) = 0;
    virtual void set(ePinId pinId) = 0;
    virtual void reset(ePinId pinId) = 0;
    virtual void toggle(ePinId pinId) = 0;
    virtual void output(ePinId pinId) = 0;
    virtual void input(ePinId pinId) = 0;
    virtual bool is_pin_set(ePinId pinId) = 0;
}; //iPinHw

#endif //__IPINHW_H__
