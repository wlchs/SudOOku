//
// Created by Borbély László on 2018. 09. 15..
//

#ifndef SUDOOKU_BASICSOLVER_H
#define SUDOOKU_BASICSOLVER_H


#include "solver.h"

class BasicSolver : Solver {
public:
    BasicSolver(Matrix, SolvingStrategy *);

    virtual std::vector<Matrix> solve();
};


#endif //SUDOOKU_BASICSOLVER_H
