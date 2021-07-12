#pragma once
#include "Strategy.h"

class OnlyRock: public Strategy {
public:
	OnlyRock();
	int getNextMove();
};