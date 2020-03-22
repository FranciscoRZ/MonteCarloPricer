#pragma once

#ifndef GUARD_Underlying_h
#define GUARD_Underlying_h

#include <string>

struct Underlying {
	double vol;
	double spot;
	double rfRate;
	std::string ticker;
};

#endif // !GUARD_Underlying_h
