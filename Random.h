#pragma once
#include "Strategy.h"

class Random : public Strategy {
public:
	Random();
	int getNextMove();
	int getFirstMove();
};