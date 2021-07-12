#ifndef ECF_CARTESIAN_SYMBREGEVALOP_H
#define ECF_CARTESIAN_SYMBREGEVALOP_H
#include <ECF/ECF.h>
#include <ECF/EvaluateOp.h>
#include <ECF/ECF_macro.h>
#include <ECF/utility/expression_evaluation.h>
#include <ECF/utility/measures.h>
#include <ECF/utility/fileparser.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <ctime>
#include "PrisonersDilemma.h"
#include "Strategy.h"
#include "AlwaysCooperate.h"
#include "AlwaysConfess.h"
#include "Grudger.h"
#include "Random.h"
#include "TitTat.h"
#include "PessimisticTitTat.h"
#include "Pavlovian.h"
#include "Alternating.h"
#include "TitForTwo.h"

class PrisonersDilemmaEvalOp : public EvaluateOp
{
private:
    std::vector<double> inputs;
    double output;

public:
    static bool play;
    PrisonersDilemmaEvalOp() {};
    FitnessP evaluate(IndividualP individual);

};
#endif //ECF_CARTESIAN_SYMBREGEVALOP_H
