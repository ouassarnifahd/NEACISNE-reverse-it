#include "Token.hpp"

namespace intexpr {

  namespace lexer {

    // Array allowing to convert token kinds into strings.
    static const std::string mapper[] = {
      "OpeningBracketKind",
      "ClosingBracketKind",
      "PlusKind",
      "MinusKind",
      "MultiplyKind",
      "DivideKind",
      "IntegerKind",
      "UnknownKind",
      "EndOfExpressionKind"
    };
    
    /*********
     * Token *
     *********/
    
    Token::Token(const TokenKind& kind, const std::string& image):
      kind_  { kind  },
      image_ { image } {
    }

    /***********
     * getKind *
     ***********/
    
    const TokenKind&
    Token::getKind() const {
      return kind_;
    }

    /************
     * getImage *
     ************/
    
    const std::string&
    Token::getImage() const {
      return image_;
    }

    /********************
     * isOpeningBracket *
     ********************/
    
    bool
    Token::isOpeningBracket() const {
      return kind_ == TokenKind::OpeningBracketKind;
    }
    
    /********************
     * isClosingBracket *
     ********************/
    
    bool
    Token::isClosingBracket() const {
      return kind_ == TokenKind::ClosingBracketKind;
    }

    /**********
     * isPlus *
     **********/
    
    bool
    Token::isPlus() const {
      return kind_ == TokenKind::PlusKind;
    }

    /***********
     * isMinus *
     ***********/
    
    bool
    Token::isMinus() const {
      return kind_ == TokenKind::MinusKind;
    }

    /**************
     * isMultiply *
     **************/
    
    bool
    Token::isMultiply() const {
      return kind_ == TokenKind::MultiplyKind;
    }

    /************
     * isDivide *
     ************/
    
    bool
    Token::isDivide() const {
      return kind_ == TokenKind::DivideKind;
    }

    /**************
     * isOperator *
     **************/
    
    bool
    Token::isOperator() const {
      switch (kind_) {
      case TokenKind::PlusKind:
      case TokenKind::MinusKind:
      case TokenKind::MultiplyKind:
      case TokenKind::DivideKind:
        return true;
      default:
        return false;
      }
    }

    /*************
     * isInteger *
     *************/
    
    bool
    Token::isInteger() const {
      return kind_ == TokenKind::IntegerKind;
    }

    /*************
     * isUnknown *
     *************/
    
    bool
    Token::isUnknown() const {
      return kind_ == TokenKind::UnknownKind;
    }

    /*********************
     * isEndOfExpression *
     *********************/ 
    
    bool
    Token::isEndOfExpression() const {
      return kind_ == TokenKind::EndOfExpressionKind;
    }

    /*********
     * print *
     *********/
    
    void
    Token::print(std::ostream& output) const {
      output << "{ "
             << mapper[static_cast< unsigned >(kind_)]
             << ", "
             << image_
             << " }";
    }

    /***********
     * println *
     ***********/
    
    void
    Token::println(std::ostream& output) const {
      print(output);
      output << std::endl;
    }
    
  }

}
