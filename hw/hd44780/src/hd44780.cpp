
#include <stdint.h>
#include <util/delay.h>
#include <stddef.h>
#include <util/delay.h>
#include "iLcdHw.hpp"
#include "iPinHw.hpp"
#include "iParallel4bit.hpp"
#include "hd44780.hpp"

PololuHD44780::PololuHD44780(iParallel4bit * parallel4bit)
{
    initialized = false;
    this->parallel4bit = parallel4bit;
}

void PololuHD44780::init()
{
    _delay_ms(15);
    write_command(command_4bit_e::function_set);
    _delay_us(4200);           // Needs to be at least 4.1 ms.
    write_command(command_4bit_e::function_set);
    _delay_us(150);            // Needs to be at least 100 us.
    write_command(command_4bit_e::function_set);

    write_command(command_4bit_e::_4bit_interface);
    write_command(e_command_mask::_4bit_2line5by8font);

    set_command(e_command_mask::display_off);
    set_command(e_command_mask::clear);
    set_entry_mode(true, e_entry_mode::scroll_right);
    set_display_control(true, e_display_control::display_on);
}

void PololuHD44780::write_data(uint8_t data)
{
    parallel4bit->write_data(data, e4or8Bits::_8_bits);
}

void PololuHD44780::gotoXY(uint8_t x, uint8_t y)
{
    // Each entry is the RAM address of a line, with its most
    // significant bit set for convenience.
    // const uint8_t line_mem[] = {0x80, 0xC0, 0x94, 0xD4}; //TODO

    // Avoid out-of-bounds array access.
    if (y > 3) { y = 3; }

    // write_command(line_mem[y] + x); //TODO

    // This could take up to 37 us according to Table 6 of the HD44780 datasheet.
    _delay_us(37);
}

void PololuHD44780::set_command(e_command_mask command)
{
    write_command(command);
    if (command == e_command_mask::clear)
    {
        // It's not clear how long this command takes because it doesn't say in
        // Table 6 of the HD44780 datasheet.  A good guess is that it takes 1.52 ms,
        // since the Return Home command does.
        _delay_us(2000);
    }
    else if (command == e_command_mask::home)
    {
        _delay_us(1600); // needs to be at least 1.52 ms
    }
}

void PololuHD44780::set_entry_mode(bool set, e_entry_mode command)
{
    e_entry_mode mode = this->entry_mode;
    if (set)
    {
        mode = mode | command;
    }
    else
    {
        mode = mode & (~command);
    }
    
    write_command(e_command_mask::entryMode | mode);
    this->entry_mode = mode;
}

void PololuHD44780::set_display_control(bool set, e_display_control command)
{
    e_display_control control = this->display_control;
    if (set)
    {
        control = control | command;
    }
    else
    {
        control = control & (~command);
    }

    write_command(e_command_mask::display_off | control);
    this->display_control = control;
}

//private
void PololuHD44780::write_command(e_command_mask cmd)
{
    parallel4bit->write_command(static_cast<uint8_t>(cmd), e4or8Bits::_8_bits);
}

void PololuHD44780::write_command(command_4bit_e cmd)
{
    parallel4bit->write_command(static_cast<uint8_t>(cmd), e4or8Bits::_4_bits);
}
