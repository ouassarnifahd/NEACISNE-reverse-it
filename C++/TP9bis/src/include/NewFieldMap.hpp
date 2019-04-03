#ifndef NewFieldMap_hpp
#define NewFieldMap_hpp

#include <algorithm>
#include <iostream>

/**
 * @class NewFieldMap NewFieldMap.hpp
 *
 * Distribution axiale ou radiale d'intensité.
 */
class NewFieldMap {
public:

    NewFieldMap(const unsigned& n,
                const double& xmin,
                const double& xmax,
                const double& init = 0.0);
    ~NewFieldMap();

    NewFieldMap(const NewFieldMap& from) = delete;
    NewFieldMap& operator=(const NewFieldMap& from) = delete;

    const unsigned& getN() const;

    const double& getXi(const unsigned& i) const;
    const double& getVi(const unsigned& i) const;

    void setVi(const unsigned& i, const double& v);

    void print(std::ostream& output) const;

private:

  /**
   * Number of sampling points.
   */
  unsigned n_;

  /**
   * Coordinates.
   */
  double* x_;

  /**
   * Values.
   */
  double* values_;

};

#endif
