#include <stdint.h>
#include "iLcdHw.hpp"
#include "iLcd.hpp"
#include "lcd.hpp"
#include "iDebug.hpp"

Lcd::Lcd(iLcdHw * lcd_hw)
{
    this->lcd_hw = lcd_hw;
    this->lcd_hw->clear_display();
}

Lcd::~Lcd()
{
    delete(lcd_hw);
}

void Lcd::write(uint8_t * data, uint8_t len)
{
    uint8_t i;
    
    lcd_hw->clear_display();
    for ( i = 0; i < len; i++ )
    {
        lcd_hw->write_data(data[i]);
    }
}

