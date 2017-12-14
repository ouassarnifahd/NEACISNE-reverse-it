#ifndef StateZero_hpp
#define StateZero_hpp

#include "state.hpp"

namespace automata {

  class StateZero: public State {

    StateZero(const StateZero& from) = delete;

  private:
    static StateZero singleton_;
    StateZero() = default;

  public:
    static const StateZero& getSingleton();
    virtual bool isTerminalState () const override;
    virtual const State& nextState(const Event& evt) const override;

  };

} /* automata */

#endif /* end of include guard: StateZero_hpp */
