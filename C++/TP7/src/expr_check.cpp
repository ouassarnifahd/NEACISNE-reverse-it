#include <iostream>
#include <cstdlib>

#include "stateZero.hpp"
#include "stateOne.hpp"
#include "stateTwo.hpp"

namespace automata {

  const State& StateZero::nextState(const Event& evt) const {
    if (evt.isLetterEvent()) {
      return StateTwo::getSingleton();
    } else {
      return StateOne::getSingleton();
    }
  }

  const State& StateTwo::nextState(const Event& evt) const {
    if (evt.isOperatorEvent()) {
      return StateZero::getSingleton();
    } else {
      return StateOne::getSingleton();
    }
  }

}

using namespace std;

int main(int argc, char const *argv[]) {
  // print help
  if (argc == 1) {
    cout << "Usage: "
         << argv[0]
         << " <expression>"
         << endl;
    return EXIT_SUCCESS;
  }

  // #arg invalid!
  if (argc != 2) {
    cerr << "Nombre d'arguments incorrect." << endl;
    return EXIT_FAILURE;
  }

  using namespace automata;
  // Pointeurs enfin du C!
  const State* current = &StateZero::getSingleton();
  for (const char& c : string(argv[1])) {
    current = &current->nextState(Event(c));
  }

  cout << "Expression"
       << ((current->isTerminalState())? " in" : " ")
       << "correcte!"
       << endl;

  // It's over.
  return EXIT_SUCCESS;
}
