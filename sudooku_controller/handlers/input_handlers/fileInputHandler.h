//
// Created by Borbély László on 2018. 10. 24..
//

#ifndef SUDOOKU_FILEINPUTHANDLER_H
#define SUDOOKU_FILEINPUTHANDLER_H

#include "inputHandler.h"
#include <string>
#include <fstream>

class FileInputHandler : public InputHandler {
private:
    std::ifstream inputFile;
    Matrix matrix;
    unsigned short int dimension;
    const char SEPARATOR = ';';

public:
    explicit FileInputHandler(std::string const &);

    virtual ~FileInputHandler();

    virtual Matrix readInput();

    virtual std::vector<SolvingStrategy *> readRules();
};

#endif //SUDOOKU_FILEINPUTHANDLER_H
