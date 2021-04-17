#pragma once

/*! \brief Main class for interfacing with the HD44780 LCDs.
 *
 * This class is suitable for controlling an HD44780 LCD assuming that the LCD's
 * RS, E, DB4, DB5, DB6, and DB7 pins are each connected to a pin on the
 * microcontroller, each of those six microcontroller pins is supported by the
 * Arduino's `pinMode` and `digitalWrite` functions, and those pins are not
 * being used for any other purpose that conflicts with the LCD.
 *
 * This class sets the E pin to be an output driving low the first time you use
 * the LCD, and it assumes that no other code will change that pin.  You cannot
 * use E for any other purposes because if the LCD sees a pulse on the E pin
 * then it might consider that to be a command or data, and the LCD state will
 * become corrupted.
 *
 * For the other pins (RS, DB4, DB5, and DB6), this library reconfigures them
 * each time they are used, so it is OK if you have other code that uses those
 * pins for other purposes.  Before writing to the LCD, you just need to disable
 * any peripherals (such as UARTs) that override the output values of those
 * pins.
 *
 * If you cannot meet these conditions, you might be able to control your LCD
 * using a custom subclass of PololuHD44780Base.  You can use this class as a
 * reference for how to do that. */
class PololuHD44780 : public PololuHD44780Base, public iLcdHw
{
private:
    iPinHw *rs, *e, *db4, *db5, *db6, *db7;
public:
    PololuHD44780(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5, iPinHw * db6, iPinHw * db7);
    void initPins();
    void send(uint8_t data, bool rsValue, bool only4bits);
    void write_data(uint8_t data);
    void clear_display();
private:
    void sendNibble(uint8_t data);
};
