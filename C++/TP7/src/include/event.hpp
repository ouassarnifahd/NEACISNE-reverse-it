#ifndef Event_hpp
#define Event_hpp

namespace automata {

  class Event {
  private:
    char value_;

  public:
    Event(const char& value);
    const char& getValue() const;
    bool isXEvent() const;
    bool isYEvent() const;
    bool isZEvent() const;
    bool isLetterEvent() const;
    bool isPlusEvent() const;
    bool isMinusEvent() const;
    bool isOperatorEvent() const;
  };

} /* automata */

#endif /* end of include guard: Event_hpp */
