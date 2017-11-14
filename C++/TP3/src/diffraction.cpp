/**
 * @mainpage
 *
 * Diffraction of a Laguerre-Gaussian LG_p0 beam through an aperture.
 */

#include <gsl/gsl_sf_exp.h>
#include <gsl/gsl_sf_laguerre.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_bessel.h>

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <complex>
#include <cstdlib>

#include "diffraction.hpp"

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

    // It's over.
    return EXIT_SUCCESS;
}

/******************************
 * calculateIntegrandRealPart *
 ******************************/

double calculateIntegrandRealPart(double rho, void* params) {

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

    /***************
    * A compléter *
    ***************/

    // It's over.
    return 0.0; // Ce n'est évidemment pas le bon résultat ...

}

/******************************
 * calculateIntegrandImagPart *
 ******************************/

double calculateIntegrandImagPart(double rho, void* params) {

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

    /***************
    * A compléter *
    ***************/

    // It's over.
    return 0.0; // Ce n'est évidemment pas le bon résultat ...

}

/*******************************
 * calculateDiffractedFieldMap *
 *******************************/

void calculateDiffractedFieldMap(const Setup& setup, FieldMap& fieldMap) {

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
  for (unsigned i = 0; i < fieldMap.n; i ++) {

    // Current radial coordinate.
    params.r = fieldMap.x[i];

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
    fieldMap.values[i] = std::norm(value);

  }

  // Workspace deallocation.
  gsl_integration_workspace_free(workspace);

}
