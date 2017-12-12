#include <iostream>
#include <fstream>
#include <cstdlib>

#include "stateZero.hpp"
#include "stateOne.hpp"
#include "stateTwo.hpp"

namespace automata {

  const State& StateZero::nextState(const Event& evt) const {
    if (evt.isLetterEvent()) {
      return StateTwo;
    } else {
      return StateOne;
    }
  }

  const State& StateTwo::nextState(const Event& evt) const {
    if (evt.isOperatorEvent()) {
      return StateZero;
    } else {
      return StateOne;
    }
  }

}

using namespace std;

int main(int argc, char const *argv[]) {
  // print help
  if (argc == 1) {
    cout << "Usage: " << argv[0] << " <expression>" << endl;
    return EXIT_SUCCESS;
  }

  // #arg invalid!
  if (argc != 2) {
    cerr << "Nombre d'arguments incorrect." << endl;
    return EXIT_FAILURE;
  }

  unsigned index = 0;
  string expression(argv[1]);
  State current(StateZero);
  while (index < expression.length() && !current.isTerminalState()) {
    Event event(expression[index]);
    current = current.nextState(event);
    index++;
  }

  // It's over.
  return EXIT_SUCCESS;
}
