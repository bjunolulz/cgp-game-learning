#include "PrisonersDilemmaEvalOp.h"
#include "./cartesian/Cartesian.h"

FitnessP PrisonersDilemmaEvalOp::evaluate(IndividualP individual) {
    int rounds = 50;
    FitnessP fitness(new FitnessMax);
    cartesian::Cartesian* cartesian = (cartesian::Cartesian*)individual->getGenotype().get();
    int value;
    PrisonersDilemma* p1 = new PrisonersDilemma(new AlwaysCooperate());
    PrisonersDilemma* p2 = new PrisonersDilemma(new AlwaysConfess());
    PrisonersDilemma* p3 = new PrisonersDilemma(new Grudger());
    PrisonersDilemma* p4 = new PrisonersDilemma(new Random());
    PrisonersDilemma* p5 = new PrisonersDilemma(new TitTat());
    PrisonersDilemma* p6 = new PrisonersDilemma(new PessimisticTitTat());
    PrisonersDilemma* p7 = new PrisonersDilemma(new Pavlovian());
    PrisonersDilemma* p8 = new PrisonersDilemma(new Alternating());
    PrisonersDilemma* p9 = new PrisonersDilemma(new TitForTwo());
    value = p1->play(rounds, cartesian, false);
    value += p2->play(rounds, cartesian, false);
    value += p3->play(rounds, cartesian, false);
    value += p4->play(rounds, cartesian, false);
    value += p5->play(rounds, cartesian, false);
    value += p6->play(rounds, cartesian, false);
    value += p7->play(rounds, cartesian, false);
    value += p8->play(rounds, cartesian, false);
    value += p9->play(rounds, cartesian, false);
    fitness->setValue(value);
    return fitness;
}