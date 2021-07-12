#pragma once
#include "Strategy.h"

class Alternating : public Strategy {
public:
	Alternating();
	int getFirstMove();
	int getNextMove(int last_my);
};