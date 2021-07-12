#include "AlwaysCooperate.h"

AlwaysCooperate::AlwaysCooperate()
{
	this->name = "Always Cooperate";
}

AlwaysCooperate::~AlwaysCooperate()
{
}

int AlwaysCooperate::getFirstMove() {
	return 1;
}

int AlwaysCooperate::getNextMove() {
	return 1;
}

