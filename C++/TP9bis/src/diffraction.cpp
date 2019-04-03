/**
 * @mainpage
 *
 * Diffraction of a Laguerre-Gaussian LG_p0 beam through an aperture.
 */

#include <gsl/gsl_sf_exp.h>
#include <gsl/gsl_sf_laguerre.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_bessel.h>

#include <fstream>
#include <cmath>
#include <complex>
#include <cstdlib>

#include "NewFieldMap.hpp"

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

// struct FieldMap {
//   unsigned n;      /** @e Number of sampling points. */
//
//   double*  x;      /** @e Coordinates.               */
//   double*  values; /** @e Intensities.               */
// };
typedef NewFieldMap FieldMap;


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
 * Constructs then returns a setup from a text input stream.
 *
 * @param[in, out] input the text input stream.
 * @return a setup.
 */
Setup makeSetup(std::istream& input);

/**
 * Constructs then returns of field map.
 *
 * @param[in] n the sampling point number.
 * @param[in] xmin the minimum coordinate.
 * @param[in] xmax the maximum coordinate.
 * @param[in] init the intensity default value.
 * @return a field map.
 */
// FieldMap makeFieldMap(const unsigned& n,
//                       const double& xmin,
//                       const double& xmax,
//                       const double& init = 0.0);

/**
 * Calculates the incident field map.
 *
 * @param[in] setup the setup.
 * @param[in, out] fieldMap the field map to calculate.
 */
void calculateIncidentFieldMap(const Setup& setup, FieldMap& fieldMap);

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

/**
 * Prints a field map onto a text output stream.
 *
 * @param[in] fieldMap the field map to print.
 * @param[in, out] output the text output stream.
 */
// void printFieldMap(const FieldMap& fieldMap, std::ostream& output);

/**
 * Main program.
 *
 * @param[in] argc number of arguments of the command line.
 * @param[in] argv arguments of the command line.
 * @return @c EXIT_SUCCESS if all the files required can be opened else
 * @c EXIT_FAILURE.
 */
int
main(int argc, char* argv[]) {

  // No argument: prints help message.
  if (argc == 1) {
    std::cout << "Synopsis"
              << std::endl
              << '\t'
              << argv[0]
              << " configuration_file incident_file diffracted_file"
              << std::endl;
    return EXIT_SUCCESS;
  }

  // Bad argument number.
  if (argc != 4) {
    std::cerr << "Bad argument number." << std::endl;
    return EXIT_FAILURE;
  }

  // Tries to open the configuration file.
  std::ifstream configurationFile(argv[1]);
  if (! configurationFile) {
    std::cerr<< "Unable to open file " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  // Tries to create the incident field file.
  std::ofstream incidentFile(argv[2]);
    if (! incidentFile) {
    std::cerr<< "Unable to create file " << argv[2] << std::endl;
    return EXIT_FAILURE;
  }

  // Tries to create the diffracted field file.
  std::ofstream diffractedFile(argv[3]);
    if (! diffractedFile) {
    std::cerr<< "Unable to create file " << argv[3] << std::endl;
    return EXIT_FAILURE;
  }

  // Makes the setup from the configuration file then closes it.
  const Setup setup = makeSetup(configurationFile);
  configurationFile.close();

  // Makes a map for the incident field, calculates it then prints it. Finally,
  // closes the corresponding file.
  {
    FieldMap fieldMap(setup.n, 0.0, setup.radius);
    // FieldMap fieldMap = makeFieldMap(setup.n, 0.0, setup.radius);
    calculateIncidentFieldMap(setup, fieldMap);
    fieldMap.print(incidentFile);
    // printFieldMap(fieldMap, incidentFile);
    incidentFile.close();
  }

  // Makes a map for the diffracted field, calculates it then prints it.
  // Finally, closes the corresponding file.
  {
    FieldMap fieldMap(setup.n, 0.0, setup.rmax);
    // FieldMap fieldMap = makeFieldMap(setup.n, 0.0, setup.rmax);
    calculateDiffractedFieldMap(setup, fieldMap);
    fieldMap.print(diffractedFile);
    // printFieldMap(fieldMap, diffractedFile);
    diffractedFile.close();
  }

  // It's over.
  return EXIT_SUCCESS;
}

/*************
 * makeSetup *
 *************/

Setup
makeSetup(std::istream& input) {

  // Our setup.
  Setup setup;

  // End of line.
  std::string endOfLine;

  // Loads configuration file.
  input >> setup.lambda; std::getline(input, endOfLine);
  input >> setup.p     ; std::getline(input, endOfLine);
  input >> setup.w     ; std::getline(input, endOfLine);
  input >> setup.s     ; std::getline(input, endOfLine);
  input >> setup.kappa ; std::getline(input, endOfLine);
  input >> setup.sf    ; std::getline(input, endOfLine);
  input >> setup.zm    ; std::getline(input, endOfLine);
  input >> setup.n     ; std::getline(input, endOfLine);
  input >> setup.rmax  ; std::getline(input, endOfLine);

  // Calculates the incident beam parameters.
  setup.k = 2.0 * M_PI / setup.lambda;
  if (setup.s > 0.0) {
    const double cst = M_PI * setup.w * setup.w * setup.s / setup.lambda;
    setup.w0 = setup.w / std::sqrt(1.0 + cst * cst);
    setup.z0 = -1.0 / (setup.s * (1.0 + 1.0 / (cst * cst)));
  }
  else {
    setup.w0 = setup.w;
    setup.z0 = 0.0;
  }
  setup.zr    = M_PI * setup.w0 * setup.w0 / setup.lambda;
  setup.gamma = std::atan2(-setup.z0, setup.zr);

  // Calculates the aperture radius.
  setup.radius = setup.w * setup.kappa;

  // It's over.
  return setup;

}

/****************
 * makeFieldMap *
 ****************/

// FieldMap
// makeFieldMap(const unsigned& n,
//              const double& xmin,
//              const double& xmax,
//              const double& init) {
//
//   // Our map.
//   FieldMap fieldMap = { n, new double[n], new double[n] };
//
//   // Initializes coordinates.
//   const double dx = (xmax - xmin) / (n - 1);
//   fieldMap.x[0] = xmin;
//   for (unsigned i = 1; i < n; i ++) {
//     fieldMap.x[i] = fieldMap.x[i - 1] + dx;
//   }
//
//   // Initializes intensities.
//   std::fill(fieldMap.values, fieldMap.values + fieldMap.n, init);
//
//   // It's over.
//   return fieldMap;
//
// }

/*****************************
 * calculateIncidentFieldMap *
 *****************************/

void
calculateIncidentFieldMap(const Setup& setup, FieldMap& fieldMap) {

  // Some constants.
  const double wSquared = setup.w * setup.w;
  const double cst      = std::sqrt(2.0 / M_PI) / setup.w;
  const double s2       = setup.s / 2.0;
  const double dist     = -setup.z0;

  // Loops over radial coordinates.
  for (unsigned long i = 0; i < fieldMap.getN(); i ++) {

    // The current radial coordinate and its square.
    const double& rho       = fieldMap.getXi(i);
    const double rhoSquared = rho * rho;

    // Calculates the field amplitude.
    const double mod =
      cst * gsl_sf_exp(- rhoSquared / wSquared) *
      gsl_sf_laguerre_n(setup.p, 0, 2.0 * rhoSquared / wSquared);

    // Calculates the field phase.
    const double arg =
      -setup.k * s2 * rhoSquared +
      (2 * setup.p + 1) * setup.gamma -
      setup.k * dist;

    // Calculates then store the field intensity.
    const double value = std::norm(std::polar< double >(mod, arg));
    fieldMap.setVi(i, value);
    // fieldMap.values[i] = value;

  }
}

/******************************
 * calculateIntegrandRealPart *
 ******************************/

double
calculateIntegrandRealPart(double rho, void* params) {

  // Casts the void* pointer to access parameters.
  const QAGParams* const parameters = static_cast< QAGParams* >(params);

  // Renamings.
  const double& k        = parameters->k;
  const unsigned& p      = parameters->p;
  const double& wSquared = parameters->wSquared;
  const double& r        = parameters->r;
  const double& zm       = parameters->zm;
  const double& s2       = parameters->s2;
  const double& sf       = parameters->sf;

  // Square of the radial coordinate at zm.
  const double rhoSquared = rho * rho;

  // Calculates the field amplitude.
  const double mod =
    gsl_sf_exp(- rhoSquared / wSquared) *
    gsl_sf_laguerre_n(p, 0, 2.0 * rhoSquared / wSquared) *
    gsl_sf_bessel_J0(k * r * rho / zm) *
    rho;

  // Calculates the field phase.
  const double arg =
    -k * s2 * rhoSquared +
    k * (sf - 1.0 / zm) * rhoSquared / 2.0;

  // It's over.
  return mod * std::cos(arg);

}

/******************************
 * calculateIntegrandImagPart *
 ******************************/

double
calculateIntegrandImagPart(double rho, void* params) {

  // Casts the void* pointer to access parameters.
  const QAGParams* const parameters = static_cast< QAGParams* >(params);

  // Renamings.
  const double& k        = parameters->k;
  const unsigned& p      = parameters->p;
  const double& wSquared = parameters->wSquared;
  const double& r        = parameters->r;
  const double& zm       = parameters->zm;
  const double& s2       = parameters->s2;
  const double& sf       = parameters->sf;

  // Square of the radial coordinate at zm.
  const double rhoSquared = rho * rho;

  // Calculates the field amplitude.
  const double mod =
    gsl_sf_exp(- rhoSquared / wSquared) *
    gsl_sf_laguerre_n(p, 0, 2.0 * rhoSquared / wSquared) *
    gsl_sf_bessel_J0(k * r * rho / zm) *
    rho;

  // Calculates the field phase.
  const double arg =
    -k * s2 * rhoSquared +
    k * (sf - 1.0 / zm) * rhoSquared / 2.0;

  // It's over.
  return mod * std::sin(arg);

}

/*******************************
 * calculateDiffractedFieldMap *
 *******************************/

void
calculateDiffractedFieldMap(const Setup& setup, FieldMap& fieldMap) {

  // QAG integrator parameters.
  QAGParams params;

  // Sets the constant parameters.
  params.k        = setup.k;
  params.p        = setup.p;
  params.wSquared = setup.w * setup.w;
  params.s2       = setup.s / 2.0;
  params.sf       = setup.sf;
  params.zm       = setup.zm;

  // Real and imaginary parts of the integrand.
  const gsl_function realPart = { &calculateIntegrandRealPart, &params };
  const gsl_function imagPart = { &calculateIntegrandImagPart, &params };

  // Modulus of the normalization constant.
  const double cstMod =
    params.k * std::sqrt(2.0 / M_PI) / setup.w / params.zm;

  // Workspace allocation.
  gsl_integration_workspace* workspace =
    gsl_integration_workspace_alloc(whichQAGSettings.n);

  // QAG error code (unused).
  double error;

  // Loops over radial coordinates.
  for (unsigned i = 0; i < fieldMap.getN(); i ++) {

    // Current radial coordinate.
    params.r = fieldMap.getXi(i);

    // Argument of the normalization constant.
    const double cstArg =
      M_PI_2 - params.k * params.zm - params.k * params.r * params.r /
      (2.0 * params.zm) +
      (2 * params.p + 1) * setup.gamma + params.k * setup.z0;

    // Normalization constant.
    const std::complex< double > cst = std::polar< double >(cstMod, cstArg);

    // Integral real part.
    double real;
    gsl_integration_qag(&realPart,
                        0.0,
                        setup.radius,
                        whichQAGSettings.epsabs,
                        whichQAGSettings.epsrel,
                        whichQAGSettings.n,
                        whichQAGSettings.key,
                        workspace,
                        &real,
                        &error);

    // Integral imaginary part.
    double imag;
    gsl_integration_qag(&imagPart,
                        0.0,
                        setup.radius,
                        whichQAGSettings.epsabs,
                        whichQAGSettings.epsrel,
                        whichQAGSettings.n,
                        whichQAGSettings.key,
                        workspace,
                        &imag,
                        &error);

    // Field value.
    const std::complex< double > value =
      cst * std::complex< double >(real, imag);

    // Calculates the field intensity then stores it.
    fieldMap.setVi(i, std::norm(value));
    // fieldMap.values[i] = std::norm(value);

  }

  // Workspace deallocation.
  gsl_integration_workspace_free(workspace);

}

/*****************
 * printFieldMap *
 *****************/

// void
// printFieldMap(const FieldMap& fieldMap, std::ostream& output) {
//   for (unsigned i = 0; i < fieldMap.n; i ++) {
//     output << fieldMap.x[i] << '\t' << fieldMap.values[i] << std::endl;
//   }
// }
