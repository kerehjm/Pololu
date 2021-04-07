#include <stdint.h>
#include "iLcdHw.hpp"
#include "iLcd.hpp"
#include "lcd.hpp"

iLcd * iLcd::create()
{
    iLcdHw * lcdHw = iLcdHw::create();
    iLcd * lcd = new Lcd(lcdHw);
    return lcd;
}
