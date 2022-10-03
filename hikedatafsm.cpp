#include "hikedatafsm.hpp"
#include <stack>

void HikeDataFSM::pushState(shared_ptr<State> state) {
  stateStack.emplace(state);
}

void HikeDataFSM::pushState(State* state) {
  pushState(shared_ptr<State>(state));
}

template<class T> void HikeDataFSM::pushState() {
  pushState(shared_ptr<State>(new T));
}

shared_ptr<State> HikeDataFSM::popState() {
  if (stateStack.empty())
    return NULL;
  auto state = getCurrentState();
  stateStack.pop();
  return state;
}

shared_ptr<State> HikeDataFSM::getCurrentState() {
  return stateStack.top();
}

bool HikeDataFSM::isAlphaString(string token) {
  if (token.length() == 0)
    return false; 
  for (string::iterator it = token.begin(); it != token.end(); it++) {
    if (!isalpha(*it))
      return false;
  }
  return true;
}

bool HikeDataFSM::isNumericString(string token) {
  if (token.length() == 0)
    return false; 
  for (string::iterator it = token.begin(); it != token.end(); it++) {
    if (!isdigit(*it))
      return false;
  }
  return true;
}

bool HikeDataFSM::isWhiteSpace(string token) {
  if (token.length() == 0)
    return false; 
  for (string::iterator it = token.begin(); it != token.end(); it++) {
    if (' ' != *it)
      return false;
  }
  return true;
}

void HikeDataFSM::performActions(string token) {
  // I need to revisit this
  if (!token.compare("Bridge")) {
    pushState<Key>();
    currentProcInfo = "Bridge";
  }
  else if (!token.compare(":")) {
    pushState<Colon>();
  }
  else if (!token.compare("    ") && token.length() == 4) {
    if (!currentProcInfo.compare("Hikers")) {
      currentProcInfo = "Bridge";
    }
  }
  else if (!token.compare("-")) {
    if (!currentProcInfo.compare("Bridge"))
      pushState<NestLevel1>();
    else if (!currentProcInfo.compare("Hikers"))
      pushState<NestLevel3>();
  }
  else if (!token.compare("BridgeName")) {
    pushState<NestLevel1Key>();
  }
  else if (!token.compare("Length")) {
    pushState<NestLevel1Key>();
  }
  else if (!token.compare("Hikers")) {
    pushState<NestLevel2Key>();
    currentProcInfo = token;
  }
  else if (!token.compare("HikerName")) {
    pushState<NestLevel3Key>();
  }
  else if (!token.compare("Speed")) {
    pushState<NestLevel3Key>();
  }
  else if (isAlphaString(token)) {
    if (!currentProcInfo.compare("Bridge")) {
      // Bridge name
      pushState<NestLevel1Value>();
    }
    else if (!currentProcInfo.compare("Hikers")) {
      // Hiker's name
      pushState<NestLevel3Value>();
    }
  }
  else if (isNumericString(token)) {
    if (!currentProcInfo.compare("Bridge")) {
      // Bridge Length
      pushState<NestLevel1Value>();
    }
    else if (!currentProcInfo.compare("Hikers")) {
      // Hiker's Speed
      pushState<NestLevel3Value>();
    }
  }
  else {
    // Process Spaces here 
    if (token.length() && true == isWhiteSpace(token)) {
      if (token.length() == 2 && !currentProcInfo.compare("Hikers")) {
        currentProcInfo = "Bridge";
      }
    }
    // Bad token
  }
}

