#pragma once
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
#include "RockPaperScissors.h"
#include "Strategy.h"
#include "OnlyPaper.h"
#include "OnlyScissors.h"
#include "OnlyRock.h"
#include "RandomRPS.h"
#include "TitForTatRPS.h"

class RPSEvalOp : public EvaluateOp
{
private:
    std::vector<double> inputs;
    double output;

public:
    RPSEvalOp() {};
    FitnessP evaluate(IndividualP individual);

};