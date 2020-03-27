#pragma once

#ifndef GUARD_Option_h
#define GUARD_Option_h
#include "Underlying.h"

enum OptionTypes {
	call,
	put
};

enum BarrierTypes {
	In,
	Out
};
enum BarrierDirections {
	Down,
	Up
};

enum BarrierEvents {
	american,
	european
};

struct Barrier {
	bool exists;
	BarrierTypes barrierType;
	BarrierDirections barrierDirection;
	BarrierEvents barrierEvent;
	double barrierLevel;
};

struct Option {
	OptionTypes optionKind;
	Barrier barrier;
	double strike;
	int daysToMaturity;
	double maturity; //maturity in years
	Underlying asset;
	double priceMC;
	double priceBS;
};

/*
class Option {
private:
	OptionTypes _optionKind;
	Barrier _barrier;
	double _strike;
	int _daysToMaturity;
	double _maturity;
	Underlying _asset;
public:
	double priceMC;
	double priceBS;
	Option();
};
*/


#endif // !define GUARD_Option_h
