//
// Created by Borbély László on 2018. 11. 01..
//

#ifndef SUDOOKU_SUDOOKUREADER_H
#define SUDOOKU_SUDOOKUREADER_H

#include <sudooku_core/matrix/matrix.h>

/**
 * Abstract class for parsing input Sudoku puzzles
 */
class SudookuReader {
public:
    virtual ~SudookuReader() = default;

    virtual std::vector<Matrix> readAll() = 0;
};

#endif //SUDOOKU_SUDOOKUREADER_H
