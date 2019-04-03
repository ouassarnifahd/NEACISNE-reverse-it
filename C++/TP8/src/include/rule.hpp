#ifndef Rule_cpp
#define Rule_cpp

#include "factbase.h"

namespace symai {

  class Rule {
    public:

      Rule(const std::string& conclusion);
      virtual ∼Rule() = default;

      const std::string& getConclusion() const;
      bool getTriggred() const;

      void triggred(FactBase& factbase);

      virtual bool canTrigger(const FactBase& factbase) const;

  };

} /* symai */

#endif /* end of include guard: Rule_cpp */
