#pragma once
#include "Strategy.h"

class RandomRPS : public Strategy {
public:
	RandomRPS();
	int getNextMove();
};