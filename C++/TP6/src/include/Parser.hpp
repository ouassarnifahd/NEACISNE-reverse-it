#ifndef Parser_hpp
#define Parser_hpp

#include "Lexer.hpp"

namespace intexpr {

  namespace parser {

    /**
     * @class Parser Parser.hpp
     * @brief Grammar parser.
     *
     * Grammar parser defined by a lexer and the last extracted token.
     */
    class Parser {
    public:

      Parser();

      void reset();

      Parser(std::istream& input);

      void reset(std::istream& input);

      std::istream& getInput() const;

      bool isConnected() const;

      bool check(std::string& msg) const;

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
