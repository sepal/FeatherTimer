
#include "App.h"

App::App(Adafruit_SSD1306 *display)
{
  this->display = display;
}

AppManager::AppManager()
  : currentApp(NULL),
    numStates(0),
    currentAppNum(0)
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
    currentApp = newState;

  // Increate the number of states counter.
  numStates++;
}

void AppManager::setApp(int index)
{
  if (currentApp != NULL)
    currentApp->onExit();

  currentApp = states[index];
  currentAppNum = index;

  if (currentApp != NULL)
    currentApp->onEnter();
}

App* AppManager::getCurrentApp() {
  return currentApp;
}
