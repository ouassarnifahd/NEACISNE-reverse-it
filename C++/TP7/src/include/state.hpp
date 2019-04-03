#ifndef State_hpp
#define State_hpp

#include "event.hpp"

namespace automata {

  class State {
  public:
    virtual ~State() = default;

  public:
    virtual bool isTerminalState () const = 0;
    virtual const State& nextState(const Event& evt) const = 0;

  };

} /* automata */

#endif /* end of include guard: State_hpp */
