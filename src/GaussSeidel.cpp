#include "GaussSeidel.h"

GaussSeidel::GaussSeidel(Coordinate* coord) {
    _coord = new Coordinate(*coord);
}

Eigen::MatrixXd GaussSeidel::solve(int Nx, int Ny, Eigen::MatrixXd A, Eigen::VectorXd b) {
    // Initialize T matrix which stores the temperatures
    Eigen::MatrixXd T = Eigen::MatrixXd::Zero(Nx+2,Ny+2);

    /*
    invhx2 : inverse of hx = 1/(Nx+1)^2
    invhy2 : inverse of hy = 1/(Ny+1)^2
    diagCoeff : Coefficients of the diagonal elements
    xFactor : the factor for the x values
    yFactor : the factor for the y values
    currIter : current number of iteration

    we define the residual norm as : residual = ( 1/(Nx*Ny) * sum(b - sum(Ax))^2 )^(1/2)
    toSquare : the value inside of the square of residual norm
    */
    double invhx2 = pow(Nx+1,2);
    double invhy2 = pow(Ny+1,2);
    double diagCoeff = -2*(invhx2 + invhy2);
    double xFactor = invhx2/diagCoeff;
    double yFactor = invhy2/diagCoeff;
    double toSquare = 0;
    int currIter = 0;
    
    


    while(true)
    {
        /*
        Consider 5 stencil
        C(i,j)T(i,j) + C(i-1,j)T(i-1,j) + C(i+1,j)T(i+1,j) + C(i,j-1)T(i,j-1) + C(i,j+1)T(i,j+1) = b(j*Nx+i)
        update each T elements iteratively
        */
        for(auto c = 1; c < Ny+1; c++)
        {
            for(auto r = 1; r < Nx+1; r++)
            {
                T(r, c) = b(r - 1 + (c-1)*Nx)/diagCoeff - xFactor*(T(r-1, c) + T(r+1, c)) - yFactor*(T(r, c-1) + T(r, c+1));
            }
        }

        currIter = currIter + 1;
        double residual = 0;

        // Calculate the residual
        for(auto i = 1; i < Nx+1; i++)
        {
            for(auto j = 1; j < Ny+1; j++)
            {
                toSquare = b(i - 1 + (j-1)*Nx) - diagCoeff*T(i, j) - invhx2*(T(i-1, j) + T(i+1, j)) - invhy2*(T(i, j-1) + T(i, j+1));
                residual = residual + toSquare*toSquare;
            }
        }     

        // if residual is below the tolerance, end computation
        // if the iteration number exceed its maximum, then stop computation and exit
        if(residual/Nx/Ny < _rtol*_rtol)
        {
            break;
        }
        else if(currIter > _maxiter)
        {
            std::cout << residual << std::endl;
            std::cout << "Exceeded maximum iteration number" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return T;
}