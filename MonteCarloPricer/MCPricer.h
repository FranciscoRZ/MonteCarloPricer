#pragma once

#ifndef GUARD_MC_Pricer_h
#define GUARD_MC_Pricer_h

#include <vector>
#include "Option.h"

/**
* Class for performing Monte Carlo simulations of process diffusions.
*/
class MCPricer {
private:
	long _numSimul, _step;
	
	/** method: Computes the next spot price in diffusion
	* @param spot: spot price of underlying asset at given timestep
	* @param vol: underlying volatility in diffusion
	* @param rf: the risk-free rate applicable to the asset
	*
	* @returns double: the next spot price in the diffusion
	*/
	double _computeStep(const double&, const double&, const double&);
	
	/** method: Simulates the entire diffusion process
	* @param asset: the asset whose diffusion we simulate
	* @param daysToMaturity: the number of days until option maturity
	*
	* @returns vector<double>: entire simulated diffusion
	*/
	std::vector<double> _simulateDiffusion(const Underlying&, const long&);

	/** Class destructor 
	*/
	~MCPricer() {};
public:
	/** Class constructor
	* @param _numSimul: Number of simulations to run
	* @param _step: Size of a single timestep in diffusion process
	*
	* @returns MCPricer: instance object of MCPricer class
	*/
	MCPricer(const long&, const long&);
	/** method: Computes the option price
	* @param option: the contract to price
	*
	* @returns double: option price
	*/
	double price(Option); 
};

#endif // !GUARD_MC_Pricer_h
