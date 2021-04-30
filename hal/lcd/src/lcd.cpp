#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "iLcdHw.hpp"
#include "iLcd.hpp"
#include "lcd.hpp"
#include "iDebug.hpp"

Lcd::Lcd(iLcdHw * lcd_hw)
{
    this->lcd_hw = lcd_hw;
    this->lcd_hw->init();
    this->lcd_hw->set_display_control(true, e_display_control::cursorBlinking);
}

Lcd::~Lcd()
{
    delete(lcd_hw);
}

void Lcd::write(const char * data)
{
    lcd_hw->set_command(e_command_mask::clear);
    while (*data != 0)
    {
        lcd_hw->write_data(*data++);
    }
}

void Lcd::print(const char *format, ...)
{
    lcd_hw->set_command(e_command_mask::clear);
    va_list args;
    va_start (args, format);
    char buffer[16];
        
    memset(buffer, '\0', sizeof(buffer));
    vsnprintf (buffer, sizeof(buffer), format, args);
    int i =0;
    while (buffer[i] != '\0')
    {
        lcd_hw->write_data(buffer[i++]);
    }
    va_end (args);
}
