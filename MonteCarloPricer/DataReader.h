#pragma once

#ifndef GUARD_DataReader_h
#define GUARD_DataReader_h

#include <string>
#include <vector>
#include "Option.h"

/** Static class for reading and deserializing input
*/
class DataReader {
private:
	/** static method: Splits the input line according to delimiting character ;
	* @param line: input string to be split
	*
	* @returns vector<string>: vector containing the elements of the input string
	*/
	static std::vector<std::string> split(const std::string&);
	/** static method: Determines if a character is the ";" delimiter
	*/
	static bool delim(const char & c);
	/** static method: Determines if a character is not the ";" delimiter
	(used as predicate for the find_if)*/
	static bool not_delim(const char& c);
	/** Class constructor
	* Made private to disallow the instanciation of this class.
	*/
	DataReader() {};
	/** Class destructor 
	*/
	~DataReader() {};
public:
	/** static method: reads the input file with the information on options to price
	* @param: path to the input file
	*
	* @returns vector<Option>: vector containing the Options to price
	*/
	static std::vector<Option> readInput(const std::string& path);
};

#endif // !GUARD_DataReader_h
