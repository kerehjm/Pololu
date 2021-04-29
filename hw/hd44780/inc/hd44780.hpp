#pragma once

#define LCD_CLEAR       0x01
#define LCD_SHOW_BLINK  0x0F
#define LCD_SHOW_SOLID  0x0E
#define LCD_HIDE        0x0C
#define LCD_CURSOR_L    0x10
#define LCD_CURSOR_R    0x14
#define LCD_SHIFT_L     0x18
#define LCD_SHIFT_R     0x1C


enum class command_4bit_e
{
    _4bit_interface = 0b0010,
    function_set    = 0b0011,
};

//TODO check risk of doing this
template<typename T, typename P>
inline T operator|(T a, P b)
{
    return static_cast<T>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

template<typename T, typename P>
inline T operator&(T a, P b)
{
    return static_cast<T>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

template<typename T>
inline T operator~(T a)
{
    return ~static_cast<T>(static_cast<uint8_t>(a));
}

class PololuHD44780 : public iLcdHw
{
private:
    iParallel4bit * parallel4bit;
    bool initialized;
    e_display_control display_control;
    e_entry_mode entry_mode;
    
public:
    PololuHD44780(iParallel4bit * Parallel4bit);
    void init();
    void write_data(uint8_t data);
    void set_entry_mode(bool set, e_entry_mode command);
    void set_display_control(bool set, e_display_control command);
    void set_command(e_command_mask command);
    void gotoXY(uint8_t x, uint8_t y);

private:
    void write_command(e_command_mask cmd);
    void write_command(command_4bit_e cmd);
};
