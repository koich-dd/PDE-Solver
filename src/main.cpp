#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <string>
#include <chrono>
#include <vector>
#include "Coordinate.h"
#include "Jacobi.h"
#include "GaussSeidel.h"


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
Solver* initialization()
{
    std::string input, coord_type, method;
    int m, n;

    // Open the file
    std::ifstream file("../config.csv");
    if (!file) {
        std::cerr << "Unable to open file\n";
    }

    // Read the single row
    std::string line;
    if (std::getline(file, line)) {
        // Create a stringstream from the line
        std::stringstream ss(line);

        // Vector to hold the parsed fields
        std::vector<std::string> fields;
        std::string field;

        // Parse the line using comma as delimiter
        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }
        coord_type = fields[0];
        m = std::stoi(fields[1]);
        n = std::stoi(fields[2]);
        method = fields[3][0];
    } else {
        std::cerr << "No data found in the file!" << std::endl;
    }

    Coordinate* coord = new Coordinate(coord_type, m, n);
    Solver* solver = solver_factory(method, coord);

    // Close the file
    file.close();

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



int main()
{
    // Measures the elapsed time 
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    // Start measurement
    start = std::chrono::system_clock::now();

    Solver* solver = initialization();
    solver->run();

    // End measurement
    end = std::chrono::system_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output elapsed time
    std::cout << "\n elapsed time: " << elapsed_time.count() << "ms\n" << std::endl;


    // ----- write to a csv file -----
    write_to_csv(solver->get_T());
}