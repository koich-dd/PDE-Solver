#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <string>
#include <chrono>
#include <vector>
#include "Coordinate.h"
#include "Jacobi.h"
#include "GaussSeidel.h"
#include "Solver.h"

Solver* solver_factory(std::string name, Coordinate* coord);
Solver* initialization(int m, int n, std::string method);
void write_to_csv(const Eigen::MatrixXd& temp);
void run(int x, int y, std::string solverType);

#endif