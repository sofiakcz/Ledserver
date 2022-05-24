#include <lgpio.h>
#include "gpio.h"
#include "config.h"

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    // initialization gpio
    m_handle = lgGpiochipOpen(CHIP);
    if (m_handle < 0)
        throw lguErrorText(m_handle);
    int init_state = 0;
    int error = 0;
    for (int pin : LEDS)
        if ((error = lgGpioClaimOutput(m_handle, LFLAGS, pin, init_state)) < 0)
            throw lguErrorText(error);
}

Gpio::~Gpio()
{
    // switch leds off
    int state = 0;
    for (int pin : LEDS)
        lgGpioWrite(m_handle, pin, state);
    lgGpiochipClose(m_handle);
}

void Gpio::set(int pin, int state)
{
    lgGpioWrite(m_handle, pin, state);
}

void Gpio::set(int pattern)
{
    // 1011
    // 0001
    //------
    // 0001
    for (int pin : LEDS) {
        int error = 0;
        int state = pattern & 0001; // mask out LSB: state = 1, 1, 0, 1
        if ((error = lgGpioWrite(m_handle, pin, state)) < 0)
            throw lguErrorText(error);
        pattern = pattern >> 1; // bit shift to the right: 1011, 0101, 0010, 0001
    }
}
