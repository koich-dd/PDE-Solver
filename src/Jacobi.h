#ifndef JACOBI_H
#define JACOBI_H

#include "Solver.h"

class Jacobi : public Solver {
    public:
        Jacobi(){}
        Jacobi(Coordinate* coord);
        Eigen::MatrixXd solve(int Nx, int Ny, Eigen::MatrixXd A, Eigen::VectorXd b) override ;
};

#endif