#include "stateZero.hpp"

namespace automata {
  // const!! clang do no want it!
  StateZero StateZero::singleton_;

  const StateZero& StateZero::getSingleton() {
    return singleton_;
  }

  bool StateZero::isTerminalState() const {
    return false;
  }


} /* automata */
