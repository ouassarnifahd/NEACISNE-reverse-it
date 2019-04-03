#include "NewFieldMap.hpp"

NewFieldMap::NewFieldMap(const unsigned& n,
                         const double& xmin,
                         const double& xmax,
                         const double& init)
                         : n_(n),
                           x_(new double[n]),
                           values_(new double[n]) {
    // Our map.
    // x_ = new double[n];
    // values_ = new double[n];

    // Initializes coordinates.
    const double dx = (xmax - xmin) / (n - 1);
    x_[0] = xmin;
    for (unsigned i = 1; i < n; i ++) {
      x_[i] = x_[i - 1] + dx;
    }

    // Initializes intensities.
    std::fill(values_, values_ + n, init);

}

NewFieldMap::~NewFieldMap() {
    delete[] x_;
    delete[] values_;
}

const unsigned& NewFieldMap::getN() const {
    return n_;
}

const double& NewFieldMap::getXi(const unsigned& i) const {
    return x_[i];
}

const double& NewFieldMap::getVi(const unsigned& i) const {
    return values_[i];
}

void NewFieldMap::setVi(const unsigned& i, const double& v) {
    values_[i] = v;
}

void NewFieldMap::print(std::ostream& output) const {
    for (unsigned i = 0; i < n_; i ++) {
      output << x_[i] << '\t' << values_[i] << std::endl;
    }
}
