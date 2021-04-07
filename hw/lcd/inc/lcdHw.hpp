#ifndef LCDHW_H_
#define LCDHW_H_

enum class eLcdLine
{
    one = 0x00,
    two = 0x40
};

enum class eLcdCommand
{
    clear           = 0b00000001,   // replace all characters with ASCII 'space'
    home            = 0b00000010,   // return cursor to first position on first line
    entryMode       = 0b00000110,   // shift cursor from left to right on read/write
    displayOff      = 0b00001000,   // turn display off
    displayOn       = 0b00001110,   // display on, cursor off, don't blink character
    functionSet     = 0b00110000,
    functionReset   = 0b00110000,   // reset the LCD
    functionSet4bit = 0b00101000,   // 4-bit data, 2-line display, 5 x 7 font
    setCursor       = 0b10000000,   // set cursor position
    displayShift    = 0b00001000,
};

class LcdHw : public iLcdHw
{
//variables
public:
protected:
private:
    iPinHw * enable;
    iPinHw * reg_select;
    iPinHw * read_write;
    iPinHw * db4;
    iPinHw * db5;
    iPinHw * db6;
    iPinHw * db7;

//functions
public:
    LcdHw(iPinHw * enable, iPinHw * reg_select, iPinHw * read_write, iPinHw * db4, iPinHw * db5, iPinHw * db6, iPinHw * db7);
    ~LcdHw();
    void write_data(uint8_t data);
    void clear_display();
protected:
private:
    void init();
    void write(uint8_t data);
    void write_command(eLcdCommand command);
};

#endif /* LCDHW_H_ */