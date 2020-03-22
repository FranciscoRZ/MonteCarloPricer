
#include "MCPricer.h"
#include <math.h>

using std::vector;

MCPricer::MCPricer(const long& numSimul, const long& step) {
	this->_numSimul = numSimul;
	this->_step = step;
}

double MCPricer::computeStep(const double& spot, const double& vol) {
	return spot + vol * sqrt(this->_step) * ;
}

vector<double> MCPricer::simulateDiffusion(const Underlying& asset, const long& daysToMaturity) {
	vector<double> diffusion;
	double spot = asset.spot;
	for (int i = 0; i != this->_step * daysToMaturity; ++i) {
		diffusion.push_back(this->computeStep(spot, asset.vol));
		spot = *diffusion.end();
	}
	return diffusion;
}

double MCPricer::price(Option option) {
	// init locals

	// simulate all diffusions

	// compute terminal payoffs

}
