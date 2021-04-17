
#include <stdint.h>
#include <util/delay.h>
#include <stddef.h>
#include <util/delay.h>
#include "iPinHw.hpp"
#include "iLcdHw.hpp"
#include "hd44780Base.hpp"
#include "hd44780.hpp"

PololuHD44780::PololuHD44780(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5,
        iPinHw * db6, iPinHw * db7)
{
    this->rs = rs;
    this->e = e;
    this->db4 = db4;
    this->db5 = db5;
    this->db6 = db6;
    this->db7 = db7;
}

void PololuHD44780::initPins()
{
    e->reset();
    e->output();
}

void PololuHD44780::send(uint8_t data, bool rsValue, bool only4bits)
{
    rs->write(rsValue);

    rs->output();
    db4->output();
    db5->output();
    db6->output();
    db7->output();

    if (!only4bits) { sendNibble(data >> 4); }
    sendNibble(data & 0x0F);
}

void PololuHD44780::sendNibble(uint8_t data)
{
    db4->write(data >> 0 & 1);
    db5->write(data >> 1 & 1);
    db6->write(data >> 2 & 1);
    db7->write(data >> 3 & 1);

    e->set();
    _delay_us(1);  // Must be at least 450 ns.
    e->reset();
    _delay_us(1);  // Must be at least 550 ns.
}

void PololuHD44780::write_data(uint8_t data)
{
    write(data);
}

void PololuHD44780::clear_display()
{
    clear();
}
