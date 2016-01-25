#ifndef _APP_STATE_
#define _APP_STATE_

#include "Arduino.h"

class AppState {
public:
  AppState();

  /**
   * Update logic and display.
   */
  virtual void update() = 0;

  /**
   * Button pressed.
   */
  virtual void pressed(uint8_t) = 0;

  /**
   * Button released.
   */
  virtual void released(uint8_t) = 0;
protected:
};

class AppStateManager {
public:
  AppStateManager();

  /**
   * Add an AppState.
   */
  void addAppState(AppState*);

  /**
   * Set the current state.
   */
   void setAppState(int index);

   /**
    * Returns a pointer to the current AppState.
    */
   AppState* getCurrentAppState();
private:
  AppState* currentState;
  AppState** states;
  uint8_t numStates;
  uint8_t currentStateNum;
};

#endif //_APP_STATE_
