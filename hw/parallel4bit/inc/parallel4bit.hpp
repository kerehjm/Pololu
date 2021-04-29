#pragma once

class Parallel4bit : public iParallel4bit
{
private:
    iPinHw *rs, *e, *db4, *db5, *db6, *db7;
public:
    Parallel4bit(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5, iPinHw * db6, iPinHw * db7);
    void write_data(uint8_t data, e4or8Bits size);
    void write_command(uint8_t data, e4or8Bits size);
private:
    void push_4_bits(uint8_t bits);
    void send_bits(uint8_t data, e4or8Bits only4bits);
};
