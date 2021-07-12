#pragma once
#include "Strategy.h"

class Pavlovian : public Strategy {
public:
	Pavlovian();
	int getFirstMove();
	int getNextMove(int last_my, int my_points);
};