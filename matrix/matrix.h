//
// Created by Borbély László on 2018. 09. 15..
//

#ifndef SUDOOKU_MATRIX_H
#define SUDOOKU_MATRIX_H

#include <map>
#include <vector>
#include "field.h"

class Matrix {
public:
    unsigned short int dimension;

    std::map<std::pair<unsigned short int, unsigned short int>, Field> fields;

    void populateEmptyFields();
public:
    Matrix(unsigned short int, std::map<std::pair<unsigned short int, unsigned short int>, Field>);

    std::vector<Field *> getListOfNontrivialFields();

    unsigned short int getDimension() const;

    void validateMatrix(std::pair<unsigned short int, unsigned short int> const &);
};


#endif //SUDOOKU_MATRIX_H
