// MonteCarloPricer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

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
	long numStepsPerDay;

	// Prompt welcome and ask for simulation inputs
	cout << "#####################################" << endl;
	cout << "   272 - Monte Carlo option pricer  " << endl;
	cout << "#####################################" << endl;
	cout << endl;
	cout << "Please input simulation parameters for option pricing: " << endl;
	cout << "Number of simulations to run per option price : ";
	cin >> numSimul;
	cout << "Number of steps to simulate per day to maturity : "; 
	cin >> numStepsPerDay;
	cout << "Thank you. Attempting to read input data for pricing." << endl;
	
	// Read the input file with the information on options to price and store in appropriate options
	string path = "input.csv";
	vector<Option> allOptions = DataReader::readInput(path);
	
	// Instanciate the Monte Carlo Pricer
	MCPricer pricer = MCPricer(numSimul, numStepsPerDay);



	return 0;
}