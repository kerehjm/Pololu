/* 
* PinHw.h
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/


#ifndef __PINHW_H__
#define __PINHW_H__

class PinHw : public iPinHw
{
//variables
public:
protected:
private:
    PinPortMap * pinPortMap;

//functions
public:
    PinHw(PinPortMap * pinPortMap);
    ~PinHw();
    void set();
    void reset();
    void toggle();
    void output();
    void input();
    bool isSet();
    void write(bool state);
protected:
private:

}; //PinHw

#endif //__PINHW_H__
