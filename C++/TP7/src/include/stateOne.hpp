#ifndef StateOne_hpp
#define StateOne_hpp

#include "state.hpp"

namespace automata {

  class StateOne: public State {

    StateOne(const StateOne& from) = delete;

  private:
    static StateOne singleton_;
    StateOne() = default;

  public:
    static const StateOne& getSingleton();
    virtual bool isTerminalState () const override;
    virtual const State& nextState(const Event& evt) const override;

  };

} /* automata */

#endif /* end of include guard: StateOne_hpp */
