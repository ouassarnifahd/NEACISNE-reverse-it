#include "Lexer.hpp"

namespace intexpr {

  namespace lexer {

    /*********
     * Lexer *
     *********/
    
    Lexer::Lexer():
      input_        { },
      line_         { },
      linePosition_ { },
      lineNumber_   { } {
    }

    /*********
     * Lexer *
     *********/
    
    Lexer::Lexer(std::istream& input):
      input_        { &input },
      line_         {        },
      linePosition_ {        },
      lineNumber_   {        } {
    }

    /************
     * getInput *
     ************/
    
    std::istream&
    Lexer::getInput() const {
      return *input_;
    }

    /***********
     * getLine *
     ***********/
    
    const std::string&
    Lexer::getLine() const {
      return line_;
    }

    /*******************
     * getLinePosition *
     *******************/
    
    const size_t&
    Lexer::getLinePosition() const {
      return linePosition_;
    }
    
    /*****************
     * getLineNumber *
     *****************/
    
    const size_t&
    Lexer::getLineNumber() const {
      return lineNumber_;
    }

    /***************
     * isConnected *
     ***************/
    
    bool
    Lexer::isConnected() const {
      return input_ != nullptr;
    }

    /*************
     * nextToken *
     *************/
    
    Token
    Lexer::nextToken() {

      // The input stream is exhausted.
      if (! forward()) {
        return Token { TokenKind::EndOfExpressionKind, "" }; 
      }
      
      // Looks at the first token character.
      switch (line_[linePosition_]) {
        
        // Opening bracket.
      case '(':
        linePosition_ ++;
        return Token { TokenKind::OpeningBracketKind, "(" };

        // Closing bracket.
      case ')':
        linePosition_ ++;
        return Token { TokenKind::ClosingBracketKind, ")" };

        // Operator plus.
      case '+':
        linePosition_ ++;
        return Token { TokenKind::PlusKind, "+" };

        // Operator minus.
      case '-':
        linePosition_ ++;
        return Token { TokenKind::MinusKind, "-" };

        // Operateur multiply.
      case '*':
        linePosition_ ++;
        return Token { TokenKind::MultiplyKind, "*" };

        // Operator divide.
      case '/':
        linePosition_ ++;
        return Token { TokenKind::DivideKind, "/" };

        // Integer literal 0.
      case '0':
        linePosition_ ++;
        return Token { TokenKind::IntegerKind, "0" };

        // Integer litteral or unknown keyword.
      default:
        // Unknown keyword.
        if (! isDigit(line_[linePosition_])) {
          const std::string image = line_.substr(linePosition_, 1);
          
          linePosition_ ++;
          return Token { TokenKind::UnknownKind, image };
        }

        // Integer litteral.
        size_t pos = linePosition_ + 1;
        while (pos != line_.size() && isDigit(line_[pos])) {
          pos ++;
        }
        const std::string image =
          line_.substr(linePosition_, pos - linePosition_);
        linePosition_ = pos;
        return Token { TokenKind::IntegerKind, image };
        
      }
      
    }
    
    /*********
     * reset *
     *********/
    
    void
    Lexer::reset() {
      input_        = { };
      line_         = { };
      linePosition_ = { };
      lineNumber_   = { };
    }

    /*********
     * reset *
     *********/
    
    void
    Lexer::reset(std::istream& input) {
      input_        = { &input };
      line_         = {        };
      linePosition_ = {        };
      lineNumber_   = {        };
    }

    /****************
     * isWhiteSpace *
     ****************/
    
    bool
    Lexer::isWhiteSpace(const char& c) const {
      return c == ' ' || c == '\t';
    }

    /***********
     * isDigit *
     ***********/

    bool
    Lexer::isDigit(const char& c) const {
      return c >= '0' && c <= '9';
    }
    
    /***********
     * forward *
     ***********/
    
    bool
    Lexer::forward() {
      
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
