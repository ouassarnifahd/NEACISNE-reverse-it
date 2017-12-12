#include "Parser.hpp"

#include <sstream>

namespace intexpr {

  namespace parser {

    // Opens lexer namespace.
    using namespace lexer;

    Parser::Parser() :
      lexer_(),
      token_(TokenKind::EndOfExpressionKind, "") {}

    void Parser::reset() {
      lexer_.reset();
      token_ = Token(TokenKind::EndOfExpressionKind, "");
    }

    Parser::Parser(std::istream& input) :
      lexer_(input),
      token_(TokenKind::EndOfExpressionKind, "") {}

    void Parser::reset(std::istream& input) {
      lexer_.reset(input);
      token_ = Token(TokenKind::EndOfExpressionKind, "");
    }

    std::istream& Parser::getInput() const {
      return lexer_.getInput();
    }

    bool Parser::isConnected() const {
      return lexer_.isConnected();
    }

    bool Parser::expression(std::string& msg) const {
      if (token_.isInteger()) {
        token_ = lexer_.nextToken();
        return true;
      }
      if (!token_.isOpeningBracket()) {
        msg = makeErrorMsg("Opening Bracket Expected!");
        return false;
      }
      token_ = lexer_.nextToken();
      if (!token_.isOperator()) {
        msg = makeErrorMsg("Operator Expected!");
        return false;
      }
      token_ = lexer_.nextToken();
      if (!expression(msg) || !expression(msg)) {
        return false;
      }
      if (!token_.isClosingBracket()) {
        msg = makeErrorMsg("Closing Bracket Expected!");
        return false;
      }
      token_ = lexer_.nextToken();
      return true;
    }

    bool Parser::check(std::string& msg) const {
      token_ = lexer_.nextToken();
      if (!expression(msg)) {
        return false;
      }
      if (!token_.isEndOfExpression()) {
        msg = makeErrorMsg("End Of Expression Expected!");
        return false;
      }
      return true;
    };

    /****************
     * makeErrorMsg *
     ****************/

    std::string Parser::makeErrorMsg(const std::string& cause) const {

      // A string builder.
      std::ostringstream builder;

      // Adds line number and error cause.
      builder << "Line "
              << lexer_.getLineNumber()
              << " : "
              << cause
              << std::endl;

      // Lexer current line and position.
      const std::string& line = lexer_.getLine();
      const size_t&      pos  = lexer_.getLinePosition();

      // Adds current line with error first character surrounded by square
      // brackets (if current line is not empty).
      if (pos > 1) {
        builder << line.substr(0, pos - 2)
                << '['
                << line[pos - 1]
                << ']'
                << line.substr(pos, line.size() - pos);
      }
      else if (pos == 1) {
        builder << '[' << line[0] << ']' << line.substr(pos, line.size() - pos);
      }

      // It's over.
      return builder.str();

    }

  }

}
