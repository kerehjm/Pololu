/* 
* iButton.h
*
* Created: 17/05/2020 12:38:52
* Author: Mathew.Kuloba
*/


#ifndef __IBUTTON_H__
#define __IBUTTON_H__

enum class eButtonId
{
    a,
    b,
    c
}; //eButtonId

class iButton
{
//functions
public:
	virtual ~iButton(){}
	virtual bool isPressed() = 0;
}; //iButton

#endif //__IBUTTON_H__
