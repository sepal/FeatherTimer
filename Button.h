#ifndef BUTTON
#define BUTTON

#include "Arduino.h"

/**
 * Button class for the featherwing oled.
  */
class Button
{
public:
  /**
   * Button object constructor.
   */
  Button();

  /**
   * Initializes the pins.
   */
  void begin();

  /**
   * Updates the states, should be called before anything else in the loop
   * function.
   */
  void update();

  /**
   * Set the pressed callback.
   */
  void setPressed(void (*pressed)(uint8_t));

  /**
   * Set the released callback.
   */
  void setReleased(void (*released)(uint8_t));

  // Buttons
  static const int UP = 0;
  static const int MID = 1;
  static const int DOWN = 2;
private:
  // Pins to which the buttons are attached to.
  const uint8_t pins[3];

  // The last states of the buttons.
  int states[3];

  // Last pin change.
  uint32_t prevMillis[3];

  // Debounce intervall.
  const uint16_t invervall = 100;

  // Function pointers for the pressed and released callback.
  void (*pressed)(uint8_t);
  void (*released)(uint8_t);
};

#endif
