
#include "MCPricer.h"
#include <math.h>
#include <cmath>
#include <random>
#include "BlackScholesFunctions.h"
#include "Option.h"
#include "Underlying.h"

using std::vector;		using std::pow;
using std::sqrt;

MCPricer::MCPricer(const long& numSimul, const long& step) //constructeur de la classe MCPRicer
{
	this->_numSimul = numSimul;
	this->_step = step;
}

double MCPricer::_computeStep(const double& spot, const Underlying& asset, const double& dt) {
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 1.0);
	double rnd = distribution(generator);
	return spot * exp((asset.rfRate - 0.5 * pow(asset.vol, 2)) * dt
				+ sqrt(this->_step) * asset.vol * rnd);
}

double MCPricer::_payoff(const Option& option, double spot)
{
	double payoff(0.0);
	if (option.optionKind == call)
	{
		payoff = std::max(spot - option.strike, 0.0);
	}
	else
	{
		payoff = std::max(option.strike - spot, 0.0);
	}
	return payoff;
}

vector<double> MCPricer::_simulateDiffusion(const Option& option) {
	vector<double> diffusion;
	double spot = option.asset.spot;
	double dt = 0.00;
	if (option.barrier.exists && option.barrier.barrierEvent == american)
	{
		dt = option.maturity / this->_step;
	}
	else
	{
		dt = option.maturity;
	}
	for (int i = 0; i != this->_step * option.maturity; ++i) {
		diffusion.push_back(this->_computeStep(spot, option.asset, dt));
		spot = *diffusion.end();
	}
	return diffusion;
}

void MCPricer::MCPricing(Option& option) {
	// init locals
	double sum(0);
	if (option.barrier.exists)
	{
		//to complete for differents barriers

	}
	else
	{
		vector<vector<double>> allPaths;
		vector<double> path;
		for (int i = 0; i < this->_numSimul; i++)
		{
			path = this->_simulateDiffusion(option);
			allPaths.push_back(path);
			sum += this->_payoff(option, allPaths[i][*path.end()]);
		}
	}
	option.priceMC = sum / this->_numSimul;
}

void MCPricer::BSPricing(Option& option)
{
	option.priceBS = BS(option);
}

