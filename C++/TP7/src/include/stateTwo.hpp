#ifndef StateTwo_hpp
#define StateTwo_hpp

#include "state.hpp"

namespace automata {

  class StateTwo: public State {

    StateTwo(const StateTwo& from) = delete;

  private:
    static StateTwo singleton_;
    StateTwo() = default;

  public:
    static const StateTwo& getSingleton();
    virtual bool isTerminalState () const override;
    virtual const State& nextState(const Event& evt) const override;

  };

} /* automata */

#endif /* end of include guard: StateTwo_hpp */
