#include "stateOne.hpp"

namespace automata {

  StateOne StateOne::singleton_;

  const StateOne& StateOne::getSingleton() {
    return singleton_;
  }

  bool StateOne::isTerminalState() const {
    return true;
  }

  const State& StateOne::nextState(const Event& evt) const {
    return getSingleton();
  }

} /* automata */
