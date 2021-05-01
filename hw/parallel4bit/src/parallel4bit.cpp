
#include <stdint.h>
#include <util/delay.h>
#include <stddef.h>
#include <util/delay.h>
#include "iPinHw.hpp"
#include "iParallel4bit.hpp"
#include "parallel4bit.hpp"

Parallel4bit::Parallel4bit(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5,
        iPinHw * db6, iPinHw * db7)
{
    this->rs = rs;
    this->e = e;
    this->db4 = db4;
    this->db5 = db5;
    this->db6 = db6;
    this->db7 = db7;

    //init pins
    e->reset();
    e->output();
}

void Parallel4bit::write_data(uint8_t data, e4or8Bits size)
{
    rs->set();
    send_bits(data, size);
}

void Parallel4bit::write_command(uint8_t data, e4or8Bits size)
{
    rs->reset();
    send_bits(data, size);
}

//private
void Parallel4bit::send_bits(uint8_t data, e4or8Bits size)
{
    rs->output();
    db4->output();
    db5->output();
    db6->output();
    db7->output();

    if (size == e4or8Bits::_8_bits)
    {
        push_4_bits(data >> 4);
    }
    push_4_bits(data & 0x0F);

    // NOTE: If we add support for configurations where the R/W line is
    // connected, then this delay and others like it should be disabled, and we
    // should instead wait for the busy flag before sending the next command.
    _delay_us(37);

    db4->input();
    db5->input();
    db6->input();
    db7->input();
}

void Parallel4bit::push_4_bits(uint8_t bits)
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
