#include "Strategy.h"

Strategy::~Strategy()
{
}

Strategy::Strategy()
{
}

Strategy::Strategy(std::string name)
{
	this->name = name;
}

int Strategy::getNextMove()
{
	return 0;
}

int Strategy::getFirstMove()
{
	return 0;
}

int Strategy::getNextMove(bool betrayed)
{
	return 0;
}

int Strategy::getNextMove(int last_ai_or_my)
{
	return 0;
}

int Strategy::getNextMove(int last_my, int my_points)
{
	return 0;
}

std::string Strategy::getName()
{
	return name;
}
