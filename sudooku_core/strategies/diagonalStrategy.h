//
// Created by Borbély László on 2018. 10. 21..
//

#ifndef SUDOOKU_DIAGONALSTRATEGY_H
#define SUDOOKU_DIAGONALSTRATEGY_H

#include "solvingStrategy.h"

class DiagonalStrategy : public SolvingStrategy {
private:
    const Matrix *constMatrix;
    unsigned short int dimension;

    bool validateInDirection(bool) const;

public:
    bool validate(Matrix const &) override;

    virtual ~DiagonalStrategy() = default;
};

#endif //SUDOOKU_DIAGONALSTRATEGY_H
