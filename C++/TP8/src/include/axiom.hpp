#ifndef Axiom_cpp
#define Axiom_cpp

#include "Rule.h"

namespace symai {

  class Axiom: public Rule {
    public:

      Axiom(const std::string& conclusion);

      const std::string& getConclusion() const;
      bool getTriggred() const;

      void triggred(FactBase& factbase);

      virtual bool canTrigger(const FactBase& factbase) const override;

  };

} /* symai */

#endif /* end of include guard: Axiom_cpp */
