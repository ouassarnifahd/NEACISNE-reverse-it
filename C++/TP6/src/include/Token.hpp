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
    enum class TokenKind {
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

      /**
       * Logic constructor.
       *
       * @param[in] kind the value of @ref kind_.
       * @param[in] image the value of @ref image_.
       */
      Token(const TokenKind& kind, const std::string& image);

    public:

      /**
       * Getter.
       *
       * @return the value of @ref kind_.
       */
      const TokenKind& getKind() const;

      /**
       * Getter.
       *
       * @return the value of @ref image_.
       */
      const std::string& getImage() const;

    public:

      /**
       * Returns @c true if this token is an opening bracket.
       *
       * @return @c true if this token is an opening bracket.
       */
      bool isOpeningBracket() const;

      /**
       * Returns @c true if this token is a closing bracket.
       *
       * @return @c true if this token is a closing bracket.
       */
      bool isClosingBracket() const;

      /**
       * Returns @c true if this token is the addition operator.
       *
       * @return @c true if this token is the addition operator.
       */
      bool isPlus() const;

      /**
       * Returns @c true if this token is the subtraction operator.
       *
       * @return @c true if this token is the subtraction operator.
       */
      bool isMinus() const;

      /**
       * Returns @c true if this token is the multiplication operator.
       *
       * @return @c true if this token is the multiplication operator.
       */
      bool isMultiply() const;

      /**
       * Returns @c true if this token is the division operator.
       *
       * @return @c true if this token is the division operator.
       */
      bool isDivide() const;

      /**
       * Returns @c true if this token is one of four operators.
       *
       * @return @c true if this token is one of four operators.
       */
      bool isOperator() const;

      /**
       * Returns @c true if this token is an integer literal.
       *
       * @return @c true if this token is an integer literal.
       */
      bool isInteger() const;

      /**
       * Returns @c true if this token is an unknown keyword.
       *
       * @return @c true if this token is an unknown keyword.
       */
      bool isUnknown() const;

      /**
       * Returns @c true if this token is an end of expression.
       *
       * @return @c true if this token is an  end of expression.
       */
      bool isEndOfExpression() const;

    public:

      /**
       * Prints this token onto a text output stream.
       *
       * @param[in, out] output the text output stream.
       */
      void print(std::ostream& output) const;

      /**
       * Prints this token followed by a CR+LF sequence onto a text output 
       * stream.
       *
       * @param[in, out] output the text output stream.
       */
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
