#ifndef ILCDHW_H_
#define ILCDHW_H_

enum class e_command_mask
{
    clear               = 0b00000001,
    home                = 0b00000010,
    _4bit_2line5by8font = 0b00101000,
    scrollDisplayLeft   = 0b00011000,
    scrollDisplayRight  = 0b00011100,
    display_off         = 0b00001000,
    entryMode           = 0b00000100,
};

enum class e_display_control
{
    cursorBlinking  = 0b001,
    show_cursor     = 0b010,
    display_on      = 0b100,
};

enum class e_entry_mode
{
    autoscroll      = 0b01,
    scroll_right    = 0b10,
};

class iLcdHw
{
public:
    static iLcdHw * create();
    virtual ~iLcdHw() {}
    virtual void init() = 0;
    virtual void write_data(uint8_t data) = 0;
    virtual void set_entry_mode(bool set, e_entry_mode command) = 0;
    virtual void set_display_control(bool set, e_display_control command) = 0;
    virtual void set_command(e_command_mask command) = 0;
    virtual void gotoXY(uint8_t x, uint8_t y) = 0;
};

#endif