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
	
	/** method: Computes the payoff of the option contract
	* @param option: option whose payoff we compute
	* @param spot: the current underlying spot price at the time of 
	* calculation
	*
	* @returns double: the payoff of the option contract
	*/
	double _payoff(const Option&, double);
	/** method: Computes the next spot price in diffusion
	* @param spot: spot price of underlying asset at given timestep
	* @param vol: underlying volatility in diffusion
	* @param rf: the risk-free rate applicable to the asset
	*
	* @returns double: the next spot price in the diffusion
	*/
	double _computeStep(const double&, const Underlying&, const double&);
	
	/** method: Simulates the entire diffusion process
	* @param asset: the asset whose diffusion we simulate
	* @param daysToMaturity: the number of days until option maturity
	*
	* @returns vector<double>: entire simulated diffusion
	*/
	std::vector<double> _simulateDiffusion(const Option&);

public:
	/** Class constructor
	* @param _numSimul: Number of simulations to run
	* @param _step: Size of a single timestep in diffusion process
	*
	* @returns MCPricer: instance object of MCPricer class
	*/
	MCPricer(const long&, const long&);
	/** method: Computes the option price and changes the option
	* BSprice property
	* @param option: the contract to price
	*/
	void BSPricing(Option&);
	/** method: Computes the option price and changes the option
	* MCprice property
	* @param option: the contract to price
	*/
	void MCPricing(Option&);
	/** Class destructor
	*/
	~MCPricer() {};
};

#endif // !GUARD_MC_Pricer_h
