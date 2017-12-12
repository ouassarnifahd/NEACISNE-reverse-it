#include "event.hpp"

namespace automata {

  Event::Event(const char& value):
    value_(value) {}

  const char& Event::getValue() const {
    return value_;
  }

  bool Event::isXEvent() const {
    return value_ == 'x';
  }

  bool Event::isYEvent() const {
    return value_ == 'y';
  }

  bool Event::isZEvent() const {
    return value_ == 'z';
  }

  bool Event::isLetterEvent() const {
    return value_ == 'z' ||
           value_ == 'y' ||
           value_ == 'x';
  }

  bool Event::isPlusEvent() const {
    return value_ == '+';
  }

  bool Event::isMinusEvent() const {
    return value_ == '-';
  }

  bool Event::isOperatorEvent() const {
    return value_ == '+' ||
           value_ == '-';
  }

} /* automata */
