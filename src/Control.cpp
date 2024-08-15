#include "Control.h"


// ----- Solver factory -----
Solver* solver_factory(std::string name, Coordinate* coord) {
    if (name == "j") {
        return new Jacobi(coord);
    } else if (name == "g") {
        return new GaussSeidel(coord);
    } else {
        return nullptr;
    }
}

// ----- Initialize parameters with the data from config.txt -----
Solver* initialization(int m, int n, std::string method)
{

    std::string coord_type = "c";

    Coordinate* coord = new Coordinate(coord_type, m, n);
    Solver* solver = solver_factory(method, coord);

    return solver;
}

// ----- write the result to csv file -----
void write_to_csv(const Eigen::MatrixXd& temp)
{
    // output result to csv
    /*
    filename : 2d_heat_equation
    ofstream object : csv_file
    */
    // open file stream
    std::ofstream csv_file("2d_heat_equation.csv");

    csv_file.setf(std::ios::fixed);

    // csv headers
    // csv_file << "Solution_of_2d_heat_equation" << std::endl;
    
    csv_file << temp;
}



void run(int x, int y, std::string solverType)
{
    // Measures the elapsed time 
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    // Start measurement
    start = std::chrono::system_clock::now();

    Solver* solver = initialization(x, y, solverType);
    solver->run();

    // End measurement
    end = std::chrono::system_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output elapsed time
    std::cout << "\n elapsed time: " << elapsed_time.count() << "ms\n" << std::endl;


    // ----- write to a csv file -----
    write_to_csv(solver->get_T());
}