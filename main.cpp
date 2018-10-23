//
// Created by Borbély László on 2018. 09. 15..
//

#include <matrix/matrixReader.h>
#include <solvers/solver.h>
#include <strategies/rowStrategy.h>
#include <strategies/groupStrategy.h>
#include <strategies/columnStrategy.h>
#include <strategies/diagonalStrategy.h>
#include <unistd.h>
#include <sudookuPrinter.h>
#include <print_matrix_to_file/printMatrixToFile.h>

void printSolutions(std::vector<Matrix> const &solutions) {
    PrintMatrixToFile view{"solutions.txt"};

    for (Matrix const &solution : solutions) {
        view.print(solution);
    }
}

void runTest(Solver &solver, Matrix const &matrix) {
    solver.setInitialMatrix(matrix);
    solver.solve();
    printSolutions(solver.getSolutions());
}

void run(Matrix const &initialMatrix, std::vector<int> const &params) {
    Solver solver{};

    RowStrategy rowStrategy{};
    ColumnStrategy columnStrategy{};
    GroupStrategy groupStrategy{};
    DiagonalStrategy diagonalStrategy{};

    solver.addRule(&rowStrategy);
    solver.addRule(&columnStrategy);
    solver.addRule(&groupStrategy);

    if (params[0] == 1) {
        solver.addRule(&diagonalStrategy);
    }

    runTest(solver, initialMatrix);
}

int main(int argc, char *argv[]) {
    int dflag = 0;
    int c;

    while ((c = getopt(argc, argv, "dp:")) != -1)
        switch (c) {
            case 'd':
                dflag = 1;
                break;
            case '?':
                if (optopt == 'p')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                return 1;
            default:
                abort();
        }

    Matrix initialMatrix = (Matrix) MatrixReader{argv[optind]};
    run(initialMatrix, {dflag});

    return 0;
}