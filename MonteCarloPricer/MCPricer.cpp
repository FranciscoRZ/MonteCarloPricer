
#include "MCPricer.h"
#include <math.h>
#include <cmath>
#include <random>

using std::vector;		using std::pow;
using std::sqrt;

MCPricer::MCPricer(const long& numSimul, const long& step) {
	this->_numSimul = numSimul;
	this->_step = step;
}

double MCPricer::computeStep(const double& spot, const double& vol, 
							 const double& rf) {
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 1.0);
	double rnd = distribution(generator);
	return spot * exp( (rf - 0.5 * pow(vol, 2)) * this->_step 
						+ sqrt(this->_step) * vol * rnd);
}

vector<double> MCPricer::simulateDiffusion(const Underlying& asset, const long& daysToMaturity, 
										   const double& rf) {
	vector<double> diffusion;
	double spot = asset.spot;
	for (int i = 0; i != this->_step * daysToMaturity; ++i) {
		diffusion.push_back(this->computeStep(spot, asset.vol, rf));
		spot = *diffusion.end();
	}
	return diffusion;
}

double MCPricer::price(Option option) {
	// init locals

	// simulate all diffusions

	// compute terminal payoffs

	return 0.0;
}
