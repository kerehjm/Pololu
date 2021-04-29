#ifndef PARALLEL4BIT_H_
#define PARALLEL4BIT_H_

enum class e4or8Bits
{
    _4_bits,
    _8_bits
};

class iParallel4bit
{
public:
    static iParallel4bit * create(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5,
        iPinHw * db6, iPinHw * db7);
    virtual ~iParallel4bit() {}
    virtual void write_data(uint8_t data, e4or8Bits size) = 0;
    virtual void write_command(uint8_t data, e4or8Bits size) = 0;
};

#endif