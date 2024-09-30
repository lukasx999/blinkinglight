#include "blink.hh"



auto
BlinkingLight::get_time(void) -> delay_t {
    return millis() + m_delay;
}


__attribute__((pure))
BlinkingLight::BlinkingLight(delay_t delay, pin_t pin)
: m_delay   (delay)
, m_time    (get_time())
, m_pin     (pin)
, m_state   {false}
, m_enabled {true}
{
    pinMode(m_pin, OUTPUT);
}

auto
BlinkingLight::loop(void) -> void {

    delay_t now = millis(); // allocate an unsigned long on the stack, initializing it with the rvalue expression of the return value of the function call of `millis`

    if (now >= m_time) {
        m_time = get_time();
        m_state = !m_state;
    }

    digitalWrite(m_pin, m_enabled && m_state);

}

auto
BlinkingLight::enable(void) -> void {
    m_enabled = true;
}

auto
BlinkingLight::disable(void) -> void {
    m_enabled = false;
}