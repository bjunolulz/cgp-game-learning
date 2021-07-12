#include <ECF/ECF.h>
#include "cartesian/Cartesian.h"
#include "PrisonersDilemmaEvalOp.h"
#include "RPSEvalOp.h"

int main(int argc, char** argv) {
    srand((unsigned)time(NULL));
    bool flag = false; //flag hocemo li evoluciju ili citanje najbolje jedinke i igranje
    bool game_flag = true; //true za PD, false za RPS

    StateP state(new State);
    CartesianP cgp(new cartesian::Cartesian);
    state->addGenotype(cgp);
    if (game_flag) 
        state->setEvalOp(new PrisonersDilemmaEvalOp);
    else 
        state->setEvalOp(new RPSEvalOp);
    state->initialize(argc, argv);
    
    IndividualP ind;

    if (flag == false) { //evolucija
        state->run();
        std::vector<IndividualP> hof = state->getHoF()->getBest();
        ind = hof[0];
        if (game_flag) {
            ofstream best("./best_PD.txt");
            best << ind->toString();
            best.close();
        }
        else {
            ofstream best("./best_RPS.txt");
            best << ind->toString();
            best.close();
        }
    }
    if (flag == true) { //citanje najbolje jedinke
        if (game_flag) {
            XMLNode xInd = XMLNode::parseFile("./best_PD.txt", "Individual");
            ind = (IndividualP) new Individual(state);
            ind->read(xInd);
        }
        else {
            XMLNode xInd = XMLNode::parseFile("./best_RPS.txt", "Individual");
            ind = (IndividualP) new Individual(state);
            ind->read(xInd);
        }
    }
    cartesian::Cartesian* cartesian = (cartesian::Cartesian*)ind->getGenotype().get();
    if (game_flag) {
        PrisonersDilemma* p = new PrisonersDilemma(new TitTat());
        int t = p->play(10, cartesian, true); //igraj s jedinkom
    }
    else {
        RockPaperScissors* p = new RockPaperScissors(new RandomRPS());
        int trash = p->play(10, cartesian, true); //igraj s jedinkom
    }

    return 0;
}
