#include "Token.hpp"

namespace intexpr {

  namespace lexer {

    // Array allowing to convert token kinds into strings.
    static const std::string mapper[] = {
      "OpeningBracket",
      "ClosingBracket",
      "Plus",
      "Minus",
      "Multiply",
      "Divide",
      "Integer",
      "Unknown",
      "EndOfExpression"
    };

    Token::Token(const TokenKind& kind, const std::string& image) : kind_(kind), image_(image) {}

    const TokenKind& Token::getKind() const {
      return kind_;
    }

    const std::string& Token::getImage() const {
      return image_;
    }

    bool Token::isOpeningBracket() const {
      return kind_ == TokenKind::OpeningBracketKind;
    }

    bool Token::isClosingBracket() const {
      return kind_ == TokenKind::ClosingBracketKind;
    }

    bool Token::isPlus() const {
      return kind_ == TokenKind::PlusKind;
    }

    bool Token::isMinus() const {
      return kind_ == TokenKind::MinusKind;
    }

    bool Token::isMultiply() const {
      return kind_ == TokenKind::MultiplyKind;
    }

    bool Token::isDivide() const {
      return kind_ == TokenKind::DivideKind;
    }

    bool Token::isOperator() const {
      return kind_ == TokenKind::PlusKind ||
             kind_ == TokenKind::MinusKind || 
             kind_ == TokenKind::MultiplyKind ||
             kind_ == TokenKind::DivideKind;
    }

    bool Token::isInteger() const {
      return kind_ == TokenKind::IntegerKind;
    }

    bool Token::isUnknown() const {
      return kind_ == TokenKind::UnknownKind;
    }

    bool Token::isEndOfExpression() const {
      return kind_ == TokenKind::EndOfExpressionKind;
    }

    void Token::print(std::ostream& output) const {
      output << "{ " << mapper[static_cast<unsigned>(kind_)] << ", " << image_ << " }";
    }

    void Token::println(std::ostream& output) const {
      output << "{ " << mapper[static_cast<unsigned>(kind_)] << ", " << image_ << " }" << std::endl;
    }

  }

}
