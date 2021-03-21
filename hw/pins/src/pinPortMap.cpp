/* 
* PinPortMap.cpp
*
* Created: 12/05/2020 15:43:49
* Author: Mathew.Kuloba
*/

#include "pinPortMap.hpp"

// default constructor
PinPortMap::PinPortMap()
{
    
}
PinPortMap::PinPortMap(
    uint8_t num,
    volatile uint8_t * port,
    volatile uint8_t * ddr,
    volatile uint8_t * pin)
{
    this->num = num;
    this->port = port,
    this->ddr = ddr;
    this->pin = pin;
} //PinPortMap

// default destructor
PinPortMap::~PinPortMap()
{
} //~PinPortMap
