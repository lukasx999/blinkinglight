#include "blink.hh"



#define NEWLIGHT(delay, pin) /*
*/ new BlinkingLight((delay), (pin))


BlinkingLight *(lights)[] = { NEWLIGHT(100, PD2),
                              NEWLIGHT(200, PD3),
                              NEWLIGHT(100, PD4),
                              NEWLIGHT(200, PD5),
                              NEWLIGHT(100, PD6),
                              NEWLIGHT(200, PD7) };

__attribute__((always_inline)) auto
setup(void) -> void {}


__attribute__((always_inline)) auto
loop(void) -> void {

  lights[0]->disable();
  lights[1]->disable();
  lights[2]->disable();

  [&, lights](void) -> void {
    for (auto light : lights) light->loop();
  }();

}