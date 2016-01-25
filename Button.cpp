
#include "Button.h"

Button::Button()
  : pressed(NULL),
    released(NULL),
    pins{9, 6, 5},
    states{HIGH, HIGH, HIGH},
    prevMillis{0, 0, 0}
{
}

void Button::begin()
{
  for (uint8_t i=0; i<3; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void Button::update()
{
  for (uint8_t i=0; i<3; i++) {
    int pin_state = digitalRead(pins[i]);

    if (pin_state != states[i]) {
      if (pin_state == HIGH) {
        if (pressed != NULL)
          pressed(i);
      } else {
        if (released != NULL)
          released(i);
      }
      states[i] = pin_state;
    }
  }
}

void Button::setPressed(void (*pressed)(uint8_t))
{
  this->pressed = pressed;
}

void Button::setReleased(void (*released)(uint8_t))
{
  this->released = released;
}
