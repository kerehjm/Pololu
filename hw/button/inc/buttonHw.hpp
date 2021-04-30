#ifndef BUTTON_HW_REG_H
#define BUTTON_HW_REG_H

extern "C" void PCINT0_vect(void) __attribute__ ((signal));
extern "C" void PCINT1_vect(void) __attribute__ ((signal));
extern "C" void PCINT2_vect(void) __attribute__ ((signal));

enum class ePcie
{
    pcie0 = 1,
    pcie1 = 2,
    pcie2 = 4,
};

enum class ePcmsk
{
    _0 = 1,
    _1 = 2,
    _2 = 4,
    _3 = 8,
    _4 = 16,
    _5 = 32,
    _6 = 64,
    _7 = 128
};

enum class eButtonIntId
{
    pcint0,
    pcint1,
    pcint2,
    max
};

inline ePcmsk operator|(ePcmsk a, ePcmsk b)
{
    return static_cast<ePcmsk>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

class ButtonHw : public iButtonHw
{
//variables
public:
protected:
private:
    iPinHw * buttonPin;
    void(*callback)(void);

    volatile uint8_t * pcicr;
    volatile uint8_t * pcmsk;

    static ButtonHw * vector_table[static_cast<uint8_t>(eButtonIntId::max)];

//functions
public:
    ButtonHw(iPinHw * buttonPin, eButtonIntId intId,
             volatile uint8_t * pcicr, volatile uint8_t * pcmsk,
             void(*callback)(void));
    ~ButtonHw();
    bool is_pressed(void);
protected:
private:
    friend void PCINT0_vect(void);
    friend void PCINT1_vect(void);
    friend void PCINT2_vect(void);
    void intHandler(eButtonIntId intId);
};

#endif
