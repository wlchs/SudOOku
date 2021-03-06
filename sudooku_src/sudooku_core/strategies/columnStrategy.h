//
// Created by Borbély László on 2018. 10. 21..
//

#ifndef SUDOOKU_COLUMNSTRATEGY_H
#define SUDOOKU_COLUMNSTRATEGY_H

#include "solvingStrategy.h"

/**
 * A SolvingStrategy to ensure there is exactly one instance of every possible value in each column of the Matrix
 */
class ColumnStrategy : public SolvingStrategy {
private:
    const Matrix *constMatrix{};
    Matrix *matrix{};
    unsigned short int row{};
    unsigned short int column{};
    unsigned short int dimension{};

    bool isColumnValid();

    bool simplifyColumn();

    bool optimizeSingular(std::vector<unsigned short int> const &);

    bool optimizeUnique(std::vector<unsigned short int> const &);

    bool recursiveRemove(unsigned short int, short int, unsigned short int);

    bool isUniqueInColumn(unsigned short int) const;

public:
    ColumnStrategy() = default;

    bool validate(Matrix const &) override;

    bool simplify(Matrix &) override;

    ~ColumnStrategy() override = default;
};

#endif //SUDOOKU_COLUMNSTRATEGY_H