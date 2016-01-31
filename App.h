#ifndef _APP_STATE_
#define _APP_STATE_

#include "Arduino.h"
#include <Adafruit_SSD1306.h>

class App {
public:
  App(Adafruit_SSD1306 *display);

  /**
   * Update logic and display.
   */
  virtual void update() = 0;

  /**
   * A button was pressed.
   */
  virtual void pressed(uint8_t) = 0;

protected:
  Adafruit_SSD1306 *display;
};

class AppManager {
public:
  AppManager();

  /**
   * Add an App.
   */
  void addApp(App*);

  /**
   * Set the current state.
   */
   void setApp(int index);

   /**
    * Returns a pointer to the current App.
    */
   App* getCurrentApp();
private:
  App* currentState;
  App** states;
  uint8_t numStates;
  uint8_t currentStateNum;
};

#endif //_APP_STATE_
