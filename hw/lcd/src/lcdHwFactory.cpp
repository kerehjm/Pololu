#include <stdint.h>
#include "iLcdHw.hpp"
#include "iPinHw.hpp"
#include "lcdHw.hpp"

iLcdHw * iLcdHw::create()
{
    iPinHw * enable = iPinHw::create(eHwPinId::PD4_LCD_ENABLE);
    iPinHw * reg_select = iPinHw::create(eHwPinId::PD2_LCD_RS);
    iPinHw * read_write = iPinHw::create(eHwPinId::PB0_LCD_RW);
    
    iPinHw * db4 = iPinHw::create(eHwPinId::PB1_LCD_DB4);
    iPinHw * db5 = iPinHw::create(eHwPinId::PB4_LCD_DB5);
    iPinHw * db6 = iPinHw::create(eHwPinId::PB5_LCD_DB6);
    iPinHw * db7 = iPinHw::create(eHwPinId::PD7_LCD_DB7);
    
    iLcdHw * lcdHw = new LcdHw(enable ,reg_select, read_write, db4, db5, db6, db7);
    return lcdHw;
}