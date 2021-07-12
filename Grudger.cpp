#include "Grudger.h"

Grudger::Grudger()
{
    this->name = "Grudger";
}

int Grudger::getNextMove(bool betrayed)
{
    if (betrayed) return 0;
    else return 1;
}

int Grudger::getFirstMove()
{
    return 1;
}
