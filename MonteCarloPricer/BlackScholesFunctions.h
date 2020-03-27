#pragma once
#ifndef GUARD_BlackScholesFunctions_h
#define GUARD_BlackScholesFunctions_h

#include "Option.h"

double BS(Option option);
double d1(Option option);
double d2(Option option);
double N(const double& x);
double norm_cdf(const double& x);

double Delta(Option option);
double Gamma(Option option);
double Vega(Option option);
double Theta(Option option);
double Rho(Option option);


#endif // !GUARD_BlackScholesFunctions_h
