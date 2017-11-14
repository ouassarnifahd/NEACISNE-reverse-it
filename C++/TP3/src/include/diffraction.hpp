#ifndef DIFFRACTION_HPP
#define DIFFRACTION_HPP

/**
 * Setup type.
 */
struct Setup {
  double   lambda;  /** @e Wavelength.                                       */
  unsigned p;       /** @e Beam order.                                       */
  double   w;       /** @e Beam width a z = 0.                               */
  double   s;       /** @e Beam inverse of the radius of curvature at z = 0. */
  double   kappa;   /** @e Aperture truncation ratio.                        */
  double   sf;      /** @e Focal length inverse.                             */
  double   zm;      /** @e Measurement plane location.                       */
  unsigned n;       /** @e Number of sampling points at zm.                  */
  double   rmax;    /** @e Maximum radial coordinate at zm.                  */

  double   k;       /** @e Wavenumber.                                       */
  double   w0;      /** @e Beam waist.                                       */
  double   z0;      /** @e Beam waist location.                              */
  double   zr;      /** @e Beam Rayleigh range.                              */
  double   gamma;   /** @e Beam Gouy phase shift.                            */

  double   radius;  /** @e Aperture radius.                                  */
};

/**
 * Field intensity map type.
 */
struct FieldMap {
  unsigned n;      /** @e Number of sampling points. */

  double*  x;      /** @e Coordinates.               */
  double*  values; /** @e Intensities.               */
};

/**
 * QAG integrator setting type.
 */
struct QAGSettings {
  unsigned n;      /** @e number of subintervals. */
  double   epsabs; /** @e Absolute error.         */
  double   epsrel; /** @e Relative error.         */
  int      key;    /** @e Quadrature rule.        */
};

/**
 * QAG parameter type.
 */
struct QAGParams {
  double   k;        /** @e Wavenumber.                                     */
  unsigned p;        /** @e Beam order.                                     */
  double   wSquared; /** @e Square of the beam width at z = 0.              */
  double   s2;       /** @e Half of the inverse of the radius of curvature. */
  double   sf;       /** @e Inverse of the focal length.                    */
  double   zm;       /** @e Measurement plane location.                     */

  double   r;        /** @e Current radial coordinate at zm.                */
};

/**
 * QAG settings to use.
 */
QAGSettings whichQAGSettings = { 1024, 1.0e-10, 1.0e-8, GSL_INTEG_GAUSS61 };

/**
 * Calculates the real part of the integrand for QAG integrator.
 *
 * @param[in] rho the radial coordinate.
 * @param[in] params parameters required for QAG integrator.
 */
double calculateIntegrandRealPart(double rho, void* params);

/**
 * Calculates the imaginary part of the integrand for QAG integrator.
 *
 * @param[in] rho the radial coordinate.
 * @param[in] params parameters required for QAG integrator.
 */
double calculateIntegrandImagPart(double rho, void* params);

/**
 * Calculates the diffracted field map.
 *
 * @param[in] setup the setup.
 * @param[in, out] fieldMap the field map to calculate.
 */
void calculateDiffractedFieldMap(const Setup& setup, FieldMap& fieldMap);

#endif /* end of include guard: DIFFRACTION_HPP */
