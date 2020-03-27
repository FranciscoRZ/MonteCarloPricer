// MonteCarloPricer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "Option.h"
#include "DataReader.h"
#include "MCPricer.h"

using std::cin;		using std::vector;
using std::cout;	using std::string;
using std::endl;	using std::ifstream;

int main()
{
	// Define MC Pricer parameters for prompt input
	long numSimul;
	long numSteps;

	// Prompt welcome and ask for simulation inputs
	cout << "#####################################" << endl;
	cout << "   272 - Monte Carlo option pricer  " << endl;
	cout << "#####################################" << endl;
	cout << endl;
	cout << "Please input simulation parameters for option pricing: " << endl;
	cout << "Number of simulations to run per option price: ";
	cin >> numSimul;
	cout << "Number of steps to simulate a path: ";
	cin >> numSteps;
	cout << "Thank you. Attempting to read input data for pricing." << endl;

	// Read the input file with the information on options to price and store in appropriate options
	string path = "input.csv";
	vector<Option> allOptions = DataReader::readInput(path);

	cout << "Done reading the input data. Starting pricing." << endl;

	// Instanciate the Monte Carlo Pricer
	MCPricer pricer = MCPricer(numSimul, numSteps);

	// Iterate over all options to price
	vector<Option>::iterator opIter;
	for (opIter = allOptions.begin(); opIter != allOptions.end(); ++opIter) {
		// dereference the iterator
		Option& temp = (*opIter);
		pricer.BSPricing(temp);
		pricer.MCPricing(temp);
	}
	
	cout << "Pricing done. Displaying results" << endl;
	for (opIter = allOptions.begin(); opIter != allOptions.end(); ++opIter) {
		// unpack the option once and for all
		Option temp = (*opIter);
		// display results
		cout << "Ticker : " << temp.asset.ticker << endl;
		cout << "Strike : " << temp.strike << " Maturity : " << temp.maturity << endl;
		cout << "BS price : " << temp.priceBS << " MC price : " << temp.priceMC << endl;
	}

	return 0;
}