#include "Mne.hpp"

namespace intexpr {

  namespace compiler {

    /*******
     * add *
     *******/
    
    std::string
    Mne::add() {
      return "add";
    }

    /*******
     * sub *
     *******/
    
    std::string
    Mne::sub() {
      return "sub";
    }

    /*******
     * mul *
     *******/
    
    std::string
    Mne::mul() {
      return "mul";
    }

    /*******
     * div *
     *******/

    std::string
    Mne::div() {
      return "div";
    }

    /********
     * push *
     ********/
    
    std::string
    Mne::push() {
      return "push";
    }

    /*********
     * print *
     *********/
    
    std::string
    Mne::print() {
      return "print";
    }    
    
  }
  
}
