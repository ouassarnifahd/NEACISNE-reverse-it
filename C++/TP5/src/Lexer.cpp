#include "Lexer.hpp"

namespace intexpr {

  namespace lexer {

    Lexer::Lexer() :
      input_(nullptr),
      line_(""),
      linePosition_(0),
      lineNumber_(0) {}

    void Lexer::reset() {
      input_ = nullptr;
      line_ = "";
      linePosition_ = 0;
      lineNumber_ = 0;
    }

    Lexer::Lexer(std::istream& input) :
      input_(&input),
      line_(""),
      linePosition_(0),
      lineNumber_(0) {}

    void Lexer::reset(std::istream& input) {
      input_ = &input;
      line_ = "";
      linePosition_ = 0;
      lineNumber_ = 0;
    }

    std::istream& Lexer::getInput() const {
      return *input_;
    }

    const std::string& Lexer::getLine() const {
      return line_;
    }

    const std::size_t& Lexer::getLinePosition() const {
      return linePosition_;
    }

    const std::size_t& Lexer::getLineNumber() const {
      return lineNumber_;
    }

    bool Lexer::isConnected() const {
      return input_ != nullptr;
    }

    Token Lexer::nextToken() {
      if (!forward()) {
        return Token(TokenKind::EndOfExpressionKind, "");
      }
      switch (line_[linePosition_++]) {
        case '(':
          return Token(TokenKind::OpeningBracketKind, "(");
        case ')':
          return Token(TokenKind::ClosingBracketKind, ")");
        case '+':
          return Token(TokenKind::PlusKind, "+");
        case '-':
          return Token(TokenKind::MinusKind, "-");
        case '*':
          return Token(TokenKind::MultiplyKind, "*");
        case '/':
          return Token(TokenKind::DivideKind, "/");
        default:
          unsigned indexBegin = linePosition_ - 1, indexEnd = indexBegin;
          while (isDigit(line_[indexEnd])) {
            indexEnd++;
          }
          if (indexEnd != indexBegin) {
            return Token(TokenKind::IntegerKind, line_.substr(indexBegin, indexEnd));
          }
          linePosition_ += line_.length() - 1;
          return Token(TokenKind::UnknownKind, line_);
      }
    }

    /****************
     * isWhiteSpace *
     ****************/

    bool Lexer::isWhiteSpace(const char& c) const {
      return c == ' ' || c == '\t';
    }

    /***********
     * isDigit *
     ***********/

    bool Lexer::isDigit(const char& c) const {
      return c >= '0' && c <= '9';
    }

    /***********
     * forward *
     ***********/

    bool Lexer::forward() {

      // Infinite loop.
      while (true) {

        // Consumes blank characters within the current line.
        while (isWhiteSpace(line_[linePosition_])) {
          linePosition_ ++;
        }

        // Since the end of the current line is not reached then we are located
        // at the first character of the next token.
        if (linePosition_ != line_.size()) {
          return true;
        }

        // Tries to read another line.
        if (! std::getline(*input_, line_)) {
          return false;
        }

        // Restarts with this new line.
        linePosition_ = 0;
        lineNumber_ ++;

      }

    }

  }

}
