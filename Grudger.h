#pragma once

#pragma once
#include "Strategy.h"

class Grudger : public Strategy {
public:
	Grudger();
	~Grudger();
	int getNextMove(bool betrayed);
	int getFirstMove();
};