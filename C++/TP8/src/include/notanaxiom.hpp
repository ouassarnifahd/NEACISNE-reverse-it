#ifndef NotAnAxiom_cpp
#define NotAnAxiom_cpp

#include "Rule.h"

namespace symai {

  class NotAnAxiom: public Rule {
    public:

      NotAnAxiom(const std::string& conclusion, const std::list<std::string>& premises);

      const std::string& getConclusion() const;
      const std::list<std::string>& getPremises() const;
      bool getTriggred() const;

      void triggred(FactBase& factbase);

      virtual bool canTrigger(const FactBase& factbase) const override;

  };

} /* symai */

#endif /* end of include guard: NotAnAxiom_cpp */
