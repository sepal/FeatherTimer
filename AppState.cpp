
#include "AppState.h"

AppState::AppState()
{

}

AppStateManager::AppStateManager()
  : currentState(NULL),
    numStates(0),
    currentStateNum(0)
{
}

void AppStateManager::addAppState(AppState* newState)
{
  // Increase the states size so we can add the new state.
  states = (AppState**) realloc(states, (numStates + 1) * sizeof(AppState*));

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

void AppStateManager::setAppState(int index)
{
  currentState = states[index];
  currentStateNum = index;
}

AppState* AppStateManager::getCurrentAppState() {
  return currentState;
}
