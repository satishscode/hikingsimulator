#include <string>
#include <boost/lockfree/stack.hpp>

using namespace std;

class State {
public:
  virtual void Actions(string) = 0;
  virtual             ~State() = default;
};

#if 0
class StateMachine {
private:
  boost::lockfree::stack<shared_ptr<State>> stateStack;
public:
  void        pushState(State* state);
  State                    popState();
  State             getCurrentState() const;
  virtual void PerformActions(string) = 0;
};
#endif

