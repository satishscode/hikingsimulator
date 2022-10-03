#include <iostream>
#include <string>
#include <boost/container/map.hpp>
#include <boost/container/list.hpp>
#include <memory>
#include <stack>
#include "statemachine.hpp"

using namespace std;

class Bridge {
  public:
    boost::container::map<string, int>        info;
    boost::container::multimap<string, int> hikers;
};

class HikingSimulatorData {
  public:
    boost::container::list<Bridge> bridges;
};

class Init : public State {
public:
  void Actions(string token) override {
  }
};

class Key : public State {
public:
  void Actions(string token) override {
  }
};

class Colon : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel0 : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel0Key : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel0Value : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel1 : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel1Key : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel1Value : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel2 : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel2Key : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel2Value : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel3 : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel3Key : public State {
public:
  void Actions(string token) override {
  }
};

class NestLevel3Value : public State {
public:
  void Actions(string token) override {
  }
};

class Close : public State {
public:
  void Actions(string token) override {
  }
};

class Bad : public State {
public:
  void Actions(string token) override {
  }
};

class HikeDataFSM {
private:
  std::stack<shared_ptr<State>> stateStack;
public:
  HikingSimulatorData hsData;
  string     currentProcInfo;

  void  pushState(shared_ptr<State> state);
  shared_ptr<State>             popState();
  shared_ptr<State>      getCurrentState();
  virtual void      performActions(string);
  void             pushState(State* state);
  template<class T> void       pushState();
  bool               isAlphaString(string);
  bool             isNumericString(string);
  bool                isWhiteSpace(string);
};

