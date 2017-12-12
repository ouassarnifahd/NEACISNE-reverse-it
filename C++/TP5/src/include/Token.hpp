#ifndef Token_hpp
#define Token_hpp

#include <iostream>

namespace intexpr {

  namespace lexer {

    /**
     * @enum TokenKind Token.hpp
     * @brief grammar token kinds.
     *
     * Grammar token kinds plus two additional tokens standing respectively
     * for unknown keywords and end of expressions.
     */
    enum class TokenKind : unsigned {
      OpeningBracketKind, /** @e '('                           */
      ClosingBracketKind, /** @e ')'                           */
      PlusKind,           /** @e '+'                           */
      MinusKind,          /** @e '-'                           */
      MultiplyKind,       /** @e '*'                           */
      DivideKind,         /** @e '/'                           */
      IntegerKind,        /** @e Integer literal.              */
      UnknownKind,        /** @e Unknown keyword.              */
      EndOfExpressionKind /** @e End of expression is reached. */
    };

    /**
     * @class Token Token.hpp
     * @brief Grammar token.
     *
     * Grammar token defined by a kind and a string image.
     */
    class Token {

    public:

      Token(const TokenKind& kind, const std::string& image);

      const TokenKind& getKind() const;
      const std::string& getImage() const;

      bool isOpeningBracket() const;
      bool isClosingBracket() const;
      bool isPlus() const;
      bool isMinus() const;
      bool isMultiply() const;
      bool isDivide() const;
      bool isOperator() const;
      bool isInteger() const;
      bool isUnknown() const;
      bool isEndOfExpression() const;

      void print(std::ostream& output) const;
      void println(std::ostream& output) const;

    private:

      /**
       * Kind.
       */
      TokenKind kind_;

      /**
       * String image.
       */
      std::string image_;

    };

  }

}

#endif
