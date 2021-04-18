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
    void write(const char * data);
    void print(const char *format, ...);
protected:
private:
};

#endif /* LCD_H_ */
