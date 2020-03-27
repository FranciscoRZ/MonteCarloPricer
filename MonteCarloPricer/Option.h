#pragma once

#ifndef GUARD_Option_h

#include "Underlying.h"

enum OptionTypes {
	call,
	put,
};

enum ExerciseTypes {
	american, 
	european
};

struct Option {
	OptionTypes optionKind;
	ExerciseTypes exercise;
	int daysToMaturity;
	Underlying asset;
	double price;
	double strike;
};

#endif // !define GUARD_Option_h
