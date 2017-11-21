#ifndef Lexer_hpp
#define Lexer_hpp

#include "Token.hpp"

#include <cstdlib>

namespace intexpr {

  namespace lexer {

    /**
     * @class Lexer Lexer.hpp
     * @brief Grammar lexer.
     *
     * Grammar lexer defined by an input text stream, a current line, a
     * position within this line and finally the line number (starting from 1).
     * Lexers can be connected several successives input text streams.
     */
    class Lexer {

      // To avoid accidental duplications.
      Lexer(const Lexer& other)            = delete;
      Lexer& operator=(const Lexer& other) = delete;

    public:

      Lexer();
      Lexer(std::istream& input);

      std::istream& getInput() const;
      const std::string& getLine() const;
      const std::size_t& getLinePosition() const;
      const std::size_t& getLineNumber() const;

      bool isConnected() const;

      void reset();
      void reset(std::istream& input);

      Token nextToken();

    private:

      /**
       * Returns @c true if a character is a white one.
       *
       * @param[in] c the character.
       * @return @c true if the character is a white one.
       */
      bool isWhiteSpace(const char& c) const;

      /**
       * Returns @c true if a character is a digit one.
       *
       * @param[in] c the character.
       * @return @c true if the character is a digit one.
       */
      bool isDigit(const char& c) const;

      /**
       * Tries to advance to the first character of the next token in the
       * text input stream.
       *
       * @return @c true if the first character of the next token was found.
       */
      bool forward();

    private:

      /**
       * Input text stream to which this lexer is connected.
       */
      std::istream* input_;

      /**
       * Current line.
       */
      std::string line_;

      /**
       * Current position within the line.
       */
      std::size_t linePosition_;

      /**
       * Line number.
       */
      std::size_t lineNumber_;

    };

  }

}

#endif
