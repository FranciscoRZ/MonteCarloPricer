#pragma once

#ifndef GUARD_MC_Pricer_h
#define GUARD_MC_Pricer_h

#include <vector>
#include "Option.h"

class MCPricer {
private:
	long _numSimul, _step;
	double computeStep(const double& spot, const double& vol);
	std::vector<double> simulateDiffusion(const Underlying&, const long&);
public:
	MCPricer(const long&, const long&);
	double price(Option);
};

#endif // !GUARD_MC_Pricer_h
