
#include "App.h"

App::App(Adafruit_SSD1306 *display)
{
  this->display = display;
}

AppManager::AppManager()
  : currentState(NULL),
    numStates(0),
    currentStateNum(0)
{
}

void AppManager::addApp(App* newState)
{
  // Increase the states size so we can add the new state.
  states = (App**) realloc(states, (numStates + 1) * sizeof(App*));

  // Return if something went wrong.
  if (states == NULL)
    return;

  // Add the new state.
  states[numStates] = newState;

  // If its the first state to be added, set it as the current state.
  if (numStates == 0)
    currentState = newState;

  // Increate the number of states counter.
  numStates++;
}

void AppManager::setApp(int index)
{
  currentState = states[index];
  currentStateNum = index;
}

App* AppManager::getCurrentApp() {
  return currentState;
}
