#include "stateTwo.hpp"

namespace automata {

  const StateTwo StateTwo::singleton_;

  const StateTwo& StateTwo::getSingleton() {
    return singleton_;
  }

  bool StateTwo::isTerminalState() const {
    return false;
  }

} /* automata */
