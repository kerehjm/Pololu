
#include <stdint.h>
#include <util/delay.h>
#include <stddef.h>
#include <util/delay.h>
#include "iPinHw.hpp"
#include "iLcdHw.hpp"
#include "hd44780.hpp"

PololuHD44780::PololuHD44780(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5,
        iPinHw * db6, iPinHw * db7)
{
    initialized = false;
    this->rs = rs;
    this->e = e;
    this->db4 = db4;
    this->db5 = db5;
    this->db6 = db6;
    this->db7 = db7;
}

void PololuHD44780::init()
{
    //init pins
    e->reset();
    e->output();

    _delay_ms(15);
    write_4bit_command(command_4bit_e::function_set);
    _delay_us(4200);           // Needs to be at least 4.1 ms.
    write_4bit_command(command_4bit_e::function_set);
    _delay_us(150);            // Needs to be at least 100 us.
    write_4bit_command(command_4bit_e::function_set);

    write_4bit_command(command_4bit_e::_4bit_interface);
    write_command(e_command_mask::_4bit_2line5by8font);

    set_command(e_command_mask::display_off);
    set_command(e_command_mask::clear);
    set_entry_mode(true, e_entry_mode::scroll_right);
    set_display_control(true, e_display_control::display_on);
}

void PololuHD44780::write_data(uint8_t data)
{
    send_bits(data, true, false);
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
void PololuHD44780::send_bits(uint8_t data, bool rsValue, bool only4bits)
{
    rs->write(rsValue);

    rs->output();
    db4->output();
    db5->output();
    db6->output();
    db7->output();

    if (!only4bits)
    {
        push_4_bits(data >> 4);
    }
    push_4_bits(data & 0x0F);

    // NOTE: If we add support for configurations where the R/W line is
    // connected, then this delay and others like it should be disabled, and we
    // should instead wait for the busy flag before sending the next command.
    _delay_us(37);
}

void PololuHD44780::push_4_bits(uint8_t bits)
{
    db4->write(bits >> 0 & 1);
    db5->write(bits >> 1 & 1);
    db6->write(bits >> 2 & 1);
    db7->write(bits >> 3 & 1);

    e->set();
    _delay_us(1);  // Must be at least 450 ns.
    e->reset();
    _delay_us(1);  // Must be at least 550 ns.
}

void PololuHD44780::write_command(e_command_mask cmd)
{
    send_bits(static_cast<uint8_t>(cmd), false, false);
}

void PololuHD44780::write_4bit_command(command_4bit_e cmd)
{
    send_bits(static_cast<uint8_t>(cmd), false, true);
}
