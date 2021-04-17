#ifndef LCD_H_
#define LCD_H_

class Lcd : public iLcd
{
//variables
public:
protected:
private:
    iLcdHw * lcd_hw;

//functions
public:
    Lcd(iLcdHw * lcd_hw);
    ~Lcd();
    void write(uint8_t * data);
protected:
private:
};

#endif /* LCD_H_ */
