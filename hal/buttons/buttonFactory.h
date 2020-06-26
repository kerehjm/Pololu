/* 
* ButtonFactory.h
*
* Created: 15/05/2020 22:27:53
* Author: Mathew.Kuloba
*/


#ifndef __BUTTONFACTORY_H__
#define __BUTTONFACTORY_H__

#include "button.h"
#include "eButtonId.h"
#include "buttonA.h"
#include "buttonB.h"
#include "buttonC.h"

class ButtonFactory
{
//functions
public:
	static iButton *create(eButtonId button_id);

}; //ButtonFactory

#endif //__BUTTONFACTORY_H__
