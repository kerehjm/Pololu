#pragma once

/*! \brief General class for handling the HD44780 protocol.
 *
 * This is an abstract class that knows about the HD44780 LCD commands but
 * does not directly read or write from the actual LCD.  To make a usable class,
 * you need to define a subclass of PololuHD44780Base and implement the
 * initPins() and send() functions.
 *
 * The subclass will inherit all the functions from PololuHD44780Base which are
 * documented here.  It will also inherit all of the functions from the Arduino `Print` class.
 * For more information about what the `Print` class provides, see the [Arduino print() documentation](http://arduino.cc/en/Serial/Print) or look at [Print.h in the Arduino IDE source code](https://github.com/arduino/Arduino/blob/master/hardware/arduino/cores/arduino/Print.h).
 *
 * Most users of this library will not need to directly use this class and
 * should use PololuHD44780 or some other subclass of PololuHD44780Base defined
 * in a different library.
 *
 * ## LCD scrolling ##
 *
 * The PololuHD44780Base class provides several functions related to scrolling:
 *
 * * scrollDisplayLeft() scrolls everything on the screen one position to the left.
 * * scrollDisplayRight() scrolls everything on the screen one position to the right.
 * * autoscroll() and noAutoscroll() control whether auto-scrolling is enabled.
 * * home() and clear() both reset the scroll position
 *
 * The HD44780 actually stores 40 columns internally.  By default, the left-most
 * internal columns are the ones that are actually displayed on the screen, but
 * the scrolling features allow that correspondence to change.  The scrolling
 * wraps around, so it is possible to display some of the right-most columns on
 * the screen at the same time as some of the left-most columns.
 *
 * For the gotoXY() function, the x coordinate actually corresponds to the
 * internal column index.  The left-most internal column has an x coordinate of
 * 0, and the right-most has an x coordinate of 39.
 *
 * For example, if you are controlling a 2&times;8 character LCD and you call
 * scrollDisplayLeft() 35 times (or call scrollDisplayRight() 5 times), then the
 * X coordinates of the columns displayed, from left to right, will be 35, 36,
 * 37, 38, 39, 0, 1, and 2.
 *
 */

class PololuHD44780Base
{
public:
    PololuHD44780Base();

    /*! Initializes the pins so that the send() function can be called
     * successfully.  This is the first step of initializing the LCD. */
    virtual void initPins() = 0;

    /*! Sends data or commands to the LCD.
     *
     * The initPins() function will always be called before the first time this
     * function is called.  This function does not need to worry about the
     * delays necessary to make sure the previous command has finished; that is
     * taken care of by PololuHD44780Base.
     *
     * This function, along with initPins(), comprise the hardware abstraction
     * layer for the LCD, and must be defined in a subclass of
     * PololuHD44780Base.  All other functions use these two functions to
     * communicate with the LCD.
     *
     * @param data The data to send to the LCD.
     * @param rsValue True to drive the RS pin high, false to drive it low.
     * @param only4bits: If true, and the LCD is using a 4-bit interface, only sends
     *   the lower 4 bits of the data. */
    virtual void send(uint8_t data, bool rsValue, bool only4bits) = 0;

    /*! Writes a single character to the LCD. */
    virtual size_t write(uint8_t c);

    /*! Writes multiple characters to the LCD.
     *
     * @param buffer Pointer to a string of characters in RAM, not
     *   necessarily null-terminated.
     * @param size The number of characters to write to the LCD, excluding any
     *  null termination character. */
    virtual size_t write(const uint8_t * buffer, size_t size);

    /*! Initialize the LCD if it has not already been initialized. */
    void init();

    /*! Reinitialize the LCD.  This performs the same initialization that is
     *  done automatically the first time any function is called that writes to
     *  the LCD.  This is useful if you want to get it back to a totally clean
     *  state. */
    void reinitialize();

private:

    void sendAndDelay(uint8_t data, bool rsValue, bool only4bit);

    /*! Sends an 8-bit command to the LCD. */
    void sendCommand(uint8_t cmd);

    /*! Sends a 4-bit command to the LCD. */
    void sendCommand4Bit(uint8_t cmd);

    /*! Sends 8 bits of a data to the LCD. */
    void sendData(uint8_t data);

public:

    /*! Clear the contents of the LCDs, resets the cursor position to the upper
     *  left, and resets the scroll position. */
    void clear();

    /*! Defines a custom character.
     * @param picture A pointer to the character dot pattern, in program space.
     * @param number A number between 0 and 7. */
    void loadCustomCharacter(const uint8_t * picture, uint8_t number);

    /*! Defines a custom character from RAM.
     * @param picture A pointer to the character dot pattern, in RAM.
     * @param number A number between 0 and 7. */
    void loadCustomCharacterFromRam(const uint8_t * picture, uint8_t number);

    /*! This overload of loadCustomCharacter is only provided for compatibility
     * with OrangutanLCD; a lot of Orangutan code defines an array of chars for
     * custom character pictures. */
    void loadCustomCharacter(const char * picture, uint8_t number);

    /*! Defines a custom character.
     * This is provided for compatibility with the LiquidCrystal library. */
    void createChar(uint8_t number, uint8_t picture[]);

    /*! Change the location of the cursor.  The cursor (whether visible or invisible),
     *  is the place where the next character written to the LCD will be displayed.
     *
     * Note that the scrolling features of the LCD change the correspondence
     * between the `x` parameter and the physical column that the data is
     * displayed on.  See the "LCD scrolling" section above for more information.
     *
     * @param x The number of the column to go to, with 0 being the leftmost column.
     * @param y The number of the row to go to, with 0 being the top row. */
    void gotoXY(uint8_t x, uint8_t y);

    /*! Changes the location of the cursor.  This is just a wrapper around
     * gotoXY provided for compaitibility with the LiquidCrystal library. */
    void setCursor(uint8_t col, uint8_t row);

    /*! Turns off the display while preserving its state.
     *
     * You can turn the display on again by calling display(). */
    void noDisplay();

    /*! Turns the display on.  This should only be needed if noDisplay() was
     *  previously called. */
    void display();

    /*! Hides the solid cursor.
     *
     * This function clears the LCD's "C" configuration bit without changing
     * the other bits.
     *
     * If the "B" bit is set to 1, a blinking cursor will still be displayed
     * even after calling this function.  For that reason, it is usually better
     * to call hideCursor() instead.  This function is only provided for
     * compatibility with the LiquidCrystal library. */
    void noCursor();

    /*! Shows the solid cursor.
     *
     * This function sets the LCD's "C" configuration bit without changing the
     * other bits.
     *
     * The cursor will normally be a solid line in the bottom row, but there
     * could be a blinking rectangle superimposed on it if previous commands
     * have enabled the blinking cursor.  For this reason, it is usually better
     * to call cursorSolid() or cursorBlinking() instead.  This function is only
     * provided for compatibility with the LiquidCrystal library. */
    void cursor();

    /*! Hides the blinking cursor.
     *
     * This functions clears the LCD's "B" configuration bit without changing
     * the other bits.
     *
     * Calling this function does not enable or disable the solid cursor (a
     * solid line in the bottom row) so it is usually better to call
     * hideCursor() or cursorSolid() instead.  This function is only provided
     * for compatibilty with the LiquidCrystal library. */
    void noBlink();

    /*! Shows the blinking cursor.
     *
     * This function sets the LCD's "B" configuration bit without changing the
     * other bits.
     *
     * The cursor will normally be a blinking rectangle, but there could also be
     * a row of solid black pixels at the bottom if previous commands have
     * enabled the solid cursor.  For this reason, it is usually better to call
     * cursorSolid() or cursorBlinking() instead.  This function is only
     * provided for compatibilty with the LiquidCrystal library. */
    void blink();

    /*! Enables a cursor that appears as a solid line in the bottom row.
     *
     * This sets the LCD's "C" configuration bit and clears its "B" bit.
     *
     * Note that the cursor will not be shown if the display is currently off
     * (due to a call to noDisplay()), or if the cursor position is not within
     * the bounds of the screen. */
    void cursorSolid();

    /*! Enables a cursor that appears as a blinking black rectangle.
     *
     * This sets the LCD's "C" and "B" configuration bits.
     *
     * Note that the cursor will not be shown if the display is currently off
     * (due to a call to noDisplay()), or if the cursor position is not within
     * the bounds of the screen. */
    void cursorBlinking();

    /*! Hides the solid and blinking cursors.
     *
     * This clears the LCD's "C" and "B" configuration bits. */
    void hideCursor();

    /*! Scrolls everything on the screen one position to the left.
     *
     * This command takes about 37 microseconds. */
    void scrollDisplayLeft();

    /*! Scrolls everything on the screen one position to the right.
     *
     * This command takes about 37 microseconds. */
    void scrollDisplayRight();

    /*! Resets the screen scrolling position back to the default and moves the
     *  cursor to the upper left corner of the screen.
     *
     * This command takes about 1600 microseconds, so it would be faster to
     * instead call scrollDisplayLeft() or scrollDisplayRight() the appropriate
     * number of times and then call gotoXY(0, 0). */
    void home();

    /*! Puts the LCD into left-to-right mode: the cursor will shift to the right
     *  after any character is written.  This is the default behavior. */
    void leftToRight();

    /*! Puts the LCD into right-to-left mode: the cursor will shift to the left
     *  after any character is written. */
    void rightToLeft();

    /*! Turns on auto-scrolling.
     *
     * When auto-scrolling is enabled, every time a character is written, the
     * screen will automatically scroll by one column in the appropriate
     * direction. */
    void autoscroll();

    /*! Turns off auto-scrolling.  Auto-scrolling is off by default. */
    void noAutoscroll();

    //void initPrintf();
    //void initPrintf(uint8_t lcdWidth, uint8_t lcdHeight);

    /*! Send an arbitrary command to the LCD.  This is here for compatibility
     * with the LiquidCrystal library. */
    void command(uint8_t cmd);

private:
    bool initialized;

    /* The lower three bits of this store the arguments to the
     * last "Display on/off control" HD44780 command that we sent.
     * bit 2: D: Whether the display is on.
     * bit 1: C: Whether the cursor is shown.
     * bit 0: B: Whether the cursor is blinking. */
    uint8_t displayControl;

    /* The lower two bits of this variable store the arguments to the
     * last "Entry mode set" HD44780 command that we sent.
     * bit 1: I/D: 0 for moving the cursor to the left after data is written,
     *        1 for moving the cursor to the right.
     * bit 0: 1 for autoscrolling. */
    uint8_t entryMode;

    void setEntryMode(uint8_t entryMode);
    void setDisplayControl(uint8_t displayControl);

    void init2();
};
