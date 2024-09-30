#pragma once
#ifndef _BLINK_H
#define _BLINK_H

#include <Arduino.h>

#define ALIASMYTYPES() /*
*/ typedef unsigned long delay_t; /*
*/ typedef const uint8_t pin_t;
ALIASMYTYPES()


class BlinkingLight {
protected:
    delay_t m_delay, m_time, get_time(void);
    pin_t   m_pin;
    bool    m_state, m_enabled;

public:
    BlinkingLight (delay_t delay, pin_t pin);
    void loop(void), enable(void), disable(void);
};




#endif // _BLINK_H