#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "Solver.h"

class GaussSeidel : public Solver {
    public:
        GaussSeidel(){}
        GaussSeidel(Coordinate* coord);
        Eigen::MatrixXd solve(int Nx, int Ny, Eigen::MatrixXd A, Eigen::VectorXd b) override;
};

#endif