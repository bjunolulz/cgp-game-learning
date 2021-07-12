#pragma once
#include "Strategy.h"
#include "ECF/ECF.h"
#include "cartesian/Cartesian.h"
#include <iostream>
#include <ctime>

class PrisonersDilemma {
private:
	Strategy *strategy;

public:
	PrisonersDilemma(Strategy* strategy) {
		this->strategy = strategy;
	}

	int play(int rounds, cartesian::Cartesian* cartesian, bool print_flag);
};