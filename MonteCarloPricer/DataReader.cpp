
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "Option.h"
#include "DataReader.h"

using std::string;		using std::vector;
using std::ifstream;	using std::cout;
using std::endl;

bool DataReader::not_delim(const char& c) {
	return (c != ';');
}

bool DataReader::delim(const char & c) {
	return (c == ';');
}

vector<string> DataReader::split(const string& line) {
	vector<string> ret;
	typedef std::string::const_iterator iter;
	iter i = line.begin();
	iter j;
	while (i != line.end()) {

		// find first iterator that is not a delimitor in line
		i = find_if(i, line.end(), not_delim);

		// find the iterator after that which is a delimitor in line
		j = find_if(i, line.end(), delim);

		// if not at end of line copy the relevant substring
		if (i != line.end()) {
			ret.push_back(string(i, j));
		}
		// advance the iterator i
		i = j;
	}
	return ret;
}

vector<Option> DataReader::readInput(const string& path) {
	
	// define local variables
	vector<Option> allOptions;
	ifstream inputFile(path);
	vector<string> inputLine;
	string line;

	if (inputFile.is_open()) {
		// skip the first line (headers)
		getline(inputFile, line);
		while (getline(inputFile, line)) {
			// split the data into relevant fields
			inputLine = split(line);

			// save the data in appropriate objects 
			Underlying asset = { atof(inputLine[3].c_str()), atof(inputLine[1].c_str()),
								 atof(inputLine[5].c_str()), inputLine[0] };
			OptionTypes type = (inputLine[6] == "Call") ? call : put;
			
			int daysToMaturity = std::stoi(inputLine[4]);
			double maturity = daysToMaturity / 252;
			Barrier barrier = { false };
			double strike = atof(inputLine[2].c_str());
			Option option = { type, barrier, strike, daysToMaturity,maturity, asset };

			// save the option to vector
			allOptions.push_back(option);

			// erase the vector
			inputLine.clear();
		}
	}
	else {
		cout << "Could not find the input file. Please move it to appropriate path." << endl;
		exit(EXIT_FAILURE);
	}
	return allOptions;
}
