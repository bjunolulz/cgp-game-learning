#include "RPSEvalOp.h"

FitnessP RPSEvalOp::evaluate(IndividualP individual)
{
    int rounds = 100;
    FitnessP fitness(new FitnessMax);
    cartesian::Cartesian* cartesian = (cartesian::Cartesian*)individual->getGenotype().get();
    int value;
    RockPaperScissors* p1 = new RockPaperScissors(new OnlyRock());
    RockPaperScissors* p2 = new RockPaperScissors(new OnlyPaper());
    RockPaperScissors* p3 = new RockPaperScissors(new OnlyScissors());
    RockPaperScissors* p4 = new RockPaperScissors(new TitForTatRPS());
    RockPaperScissors* p5 = new RockPaperScissors(new RandomRPS());
    value = p1->play(rounds, cartesian, false);
    value += p2->play(rounds, cartesian, false);
    value += p3->play(rounds, cartesian, false);
    value += p4->play(rounds, cartesian, false);
    value += p5->play(rounds, cartesian, false);
    fitness->setValue(value);
    return fitness;
}
