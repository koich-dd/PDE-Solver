#ifndef SOLVER_H
#define SOLVER_H
#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <string>
#include "Coordinate.h"

class Solver
{
    protected:
        /*
        _rtol : tolerance for the error
        _maxiter : maximum number of iteration
        _T : the matrix which stores the solution
        */
        double _rtol = pow(10,-4);
        int _maxiter = pow(10,4);
        std::string _solver;
        Coordinate* _coord;
        Eigen::MatrixXd _T;
    
    public:
        /*
        solve : Call a method to solve PDE.
        get_T : returns T matrix.
        */
        Solver(){}
        virtual Eigen::MatrixXd solve(int Nx, int Ny, Eigen::MatrixXd A, Eigen::VectorXd b) = 0;
        void run()
        {
            _T = solve(_coord->get_m(), _coord->get_n(), _coord->get_mat(), _coord->get_vec());
        }
        Eigen::MatrixXd get_T()
        {
            return _T;
        }
};

#endif