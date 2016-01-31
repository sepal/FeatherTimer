#ifndef _APP_STATE_
#define _APP_STATE_

#include "Arduino.h"
#include <Adafruit_SSD1306.h>

class App {
public:
  App(Adafruit_SSD1306 *display);

  /**
   * Invoked after switching to this app.
   */
  virtual void onEnter() = 0;

  /**
   * Invoked before switching to another app.
   */
  virtual void onExit() = 0;

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
  App* currentApp;
  App** states;
  uint8_t numStates;
  uint8_t currentAppNum;
};

#endif //_APP_STATE_
