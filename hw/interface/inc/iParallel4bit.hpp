#ifndef ISIMPLEPARALLEL_H_
#define ISIMPLEPARALLEL_H_

enum class e4or8Bits
{
    _4_bits,
    _8_bits
};

class iParallel4bit
{
public:
    static iParallel4bit * create();
    virtual ~iParallel4bit() {}
    virtual void write_data(uint8_t data, e4or8Bits size) = 0;
    virtual void write_command(uint8_t data, e4or8Bits size) = 0;
};

#endif