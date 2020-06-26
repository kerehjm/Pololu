/* 
* PinPortMap.h
*
* Created: 12/05/2020 15:43:49
* Author: Mathew.Kuloba
*/


#ifndef __PINPORTMAP_H__
#define __PINPORTMAP_H__

#include <avr/io.h>
#include <stdint.h>

class PinPortMap
{
//variables
public:
    uint8_t num;
    volatile uint8_t *port;
    volatile uint8_t *ddr;
protected:
private:

//functions
public:
    PinPortMap();
	PinPortMap(
        uint8_t num,
	    volatile uint8_t *port,
	    volatile uint8_t *ddr
    );
	~PinPortMap();
protected:
private:

}; //PinPortMap

#endif //__PINPORTMAP_H__
