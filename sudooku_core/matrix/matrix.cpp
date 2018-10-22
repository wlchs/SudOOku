#include <utility>

//
// Created by Borbély László on 2018. 09. 15..
//

#include "matrix.h"
#include <vector>

Matrix::Matrix(Matrix const &matrix) {
    dimension = matrix.dimension;
    fields = matrix.fields;
    forkHelper = new ForkHelper{this};
}

void Matrix::populateEmptyFields() {
    std::vector<unsigned short int> allValues = {};

    for (unsigned short int i = 1; i <= dimension; ++i) {
        allValues.push_back(i);
    }

    for (unsigned short int row = 1; row <= dimension; ++row) {
        for (unsigned short int column = 1; column <= dimension; ++column) {
            if (fields.find(std::pair<unsigned short int, unsigned short int>(row, column)) == fields.end()) {
                fields[{row, column}] = Field(allValues);
            }
        }
    }
}

Matrix::Matrix(unsigned short const int dimension,
               std::map<std::pair<unsigned short int, unsigned short int>, Field> const &fields) {
    this->dimension = dimension;
    this->fields = fields;
    populateEmptyFields();
    this->forkHelper = new ForkHelper{this};
}

Matrix &Matrix::operator=(Matrix const &matrix) {
    if (this != &matrix) {
        delete forkHelper;
        dimension = matrix.dimension;
        fields = matrix.fields;
        forkHelper = new ForkHelper{this};
    }

    return *this;
}

bool Matrix::operator==(Matrix const &matrix) const {
    if (dimension != matrix.getDimension()) {
        return false;
    }

    for (unsigned short int row = 1; row <= dimension; ++row) {
        for (unsigned short int column = 1; column <= dimension; ++column) {
            auto values1 = (*this)[{row, column}].getPossibleValues();
            auto values2 = matrix[{row, column}].getPossibleValues();

            if (values1.size() != values2.size()) {
                return false;
            }

            for (unsigned short int i = 0; i < values1.size(); ++i) {
                if (values1[i] != values2[i]) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Matrix::operator!=(Matrix const &matrix) const {
    return !((*this) == matrix);
}

Matrix::~Matrix() {
    delete forkHelper;
}

unsigned short int Matrix::getDimension() const {
    return dimension;
}

Field &Matrix::operator[](std::pair<unsigned short int, unsigned short int> const &coordinates) {
    return fields.at(coordinates);
}

Field const &Matrix::operator[](std::pair<unsigned short int, unsigned short int> const &coordinates) const {
    return fields.at(coordinates);
}

Matrix Matrix::forkFirstReturnSecond() {
    return forkHelper->fork();
}

void Matrix::notifyChangeAt(std::pair<unsigned short int, unsigned short int> const &coordinates) {
    forkHelper->notify(coordinates);
}