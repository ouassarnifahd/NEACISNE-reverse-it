#ifndef Compiler_hpp
#define Compiler_hpp

#include "Parser.hpp"

namespace intexpr {

  namespace compiler {

    class Compiler {
    public:

      Compiler();

      void reset();

      Compiler(std::istream& input, std::ostream& output);

      void reset(std::istream& input, std::ostream& output);

      std::istream& getInput() const;

      std::ostream& getOutput() const;

      bool isConnected() const;

      bool compile(std::string& msg) const;

    private:

      /**
       * Constructs then returns an error message based on the lexer
       * informations.
       *
       * @param[in] cause the error cause.
       * @return an error message based on the lexer informations.
       */
      std::string makeErrorMsg(const std::string& cause) const;

      bool expression(std::string& msg) const;

    private:

      /**
       * Grammar lexer.
       */
      lexer::Lexer lexer_;

      /**
       * Last extracted token.
       */
      lexer::Token token_;

    };

  }

}

#endif
