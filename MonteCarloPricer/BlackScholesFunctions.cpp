#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#include <cmath>
#include <random>

#include "BlackScholesFunctions.h"
using namespace std;

double BS(Option option)
{
	double K = option.asset.spot;
	double price;
	switch (option.optionKind) {

	case OptionTypes::call:
		price = option.asset.spot * N(d1(option)) - K * exp(-option.asset.rfRate * option.maturity) * N(d2(option));
		break;
	case OptionTypes::put:
		price = K * exp(-option.asset.rfRate * option.maturity) * N(-d2(option)) - option.asset.spot * N(-d1(option));
		break;
	}

	return price;
}

double d1(Option option)
{
	double K = option.asset.spot;
	return (log(option.asset.spot / K) + (option.asset.rfRate - 0.5 * pow(option.asset.vol, 2)) * option.maturity) / (option.asset.vol * sqrt(option.maturity));
}
double d2(Option option)
{
	return d1(option) - option.asset.vol * sqrt(option.maturity);
}

double N(double const& x) //norm cdf
{
	return(1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * pow(x, 2));
}

double norm_cdf(const double& x) {
	double k = 1.0 / (1.0 + 0.2316419 * x);
	double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

	if (x >= 0.0) {
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
	}
	else {
		return 1.0 - norm_cdf(-x);
	}
}

double Delta(Option option)
{
	double delta;
	switch (option.optionKind)
	{
	case OptionTypes::call:
		delta = N(d1(option));
		break;
	case OptionTypes::put:
		delta = N(d1(option)) - 1;
		break;
	}
	return delta;
}

double Gamma(Option option)
{
	double gamma = N(d1(option)) / (option.asset.spot * option.asset.vol * sqrt(option.maturity));
	return gamma;
}

double Vega(Option option)
{
	double  vega = option.asset.spot * sqrt(option.maturity) * N(d1(option));
	return vega;
}

double Theta(Option option)
{
	double K = option.asset.spot;
	double theta;
	switch (option.optionKind)
	{
	case OptionTypes::call:
		theta = -option.asset.spot * N(d1(option)) * option.asset.vol / (2 * sqrt(option.maturity));
		theta += -option.asset.rfRate * K * exp(-option.asset.rfRate * (option.maturity)) * N(d2(option));
		break;
	case OptionTypes::put:
		theta = -option.asset.spot * N(d1(option)) * option.asset.vol / (2 * sqrt(option.maturity));
		theta += option.asset.rfRate * K * exp(-option.asset.rfRate * (option.maturity)) * N(-d2(option));
		break;
	}
	return theta;
}

double Rho(Option option)
{
	double K = option.asset.spot;
	double rho;
	switch (option.optionKind)
	{
	case OptionTypes::call:
		rho = K * (option.maturity) * exp(-option.asset.rfRate * (option.maturity)) * N(d2(option));
		break;
	case OptionTypes::put:
		rho = -K * (option.maturity) * exp(-option.asset.rfRate * (option.maturity)) * N(-d2(option));
		break;
	}
	return rho;
}


