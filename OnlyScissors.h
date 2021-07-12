#pragma once
#include "Strategy.h"

class OnlyScissors : public Strategy {
public:
	OnlyScissors();
	int getNextMove();
};