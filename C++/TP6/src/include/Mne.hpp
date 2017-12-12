#ifndef Mne_hpp
#define Mne_hpp

#include <string>

namespace intexpr {

  namespace compiler {

    /**
     * @class Mne Mne.hpp
     * @brief Bytecode mnemonic.
     *
     * Bytecode mnemonic defined by its string image.
     */
    class Mne {

      // No need to instanciate this class.
      Mne() = delete;
      
    public:
      
      /**
       * Returns the string image of mne add.
       *
       * @return the string image of mne add.
       */
      static std::string add();

      /**
       * Returns the string image of mne sub.
       *
       * @return the string image of mne sub.
       */
      static std::string sub();

      /**
       * Returns the string image of mne mul.
       *
       * @return the string image of mne mul.
       */
      static std::string mul();

      /**
       * Returns the string image of mne div.
       *
       * @return the string image of mne div.
       */
      static std::string div();

      /**
       * Returns the string image of mne push.
       *
       * @return the string image of mne push.
       */
      static std::string push();

      /**
       * Returns the string image of mne print.
       *
       * @return the string image of mne print.
       */
      static std::string print();
                  
    };

  }
  
}

#endif
