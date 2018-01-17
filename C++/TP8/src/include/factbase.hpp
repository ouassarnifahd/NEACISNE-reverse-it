#ifndef FactBase_cpp
#define FactBase_cpp

#include "Rule.h"

namespace symai {

  class FactBase {
    public:

      FactBase(const std::string& conclusion);

      void addFact(const std::string& fact);

      bool contains(const std::string& fact) const;

      const std::string& toString();

  };

} /* symai */

#endif /* end of include guard: FactBase_cpp */
