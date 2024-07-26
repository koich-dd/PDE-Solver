#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <string>
#include <chrono>
#include "Coordinate.h"
#include "Solver.h"



Solver initialization()
{
    std::string input, c_type, method;
    int m, n;

    std::ifstream config;
    config.open("../config.txt", std::ios::in);
    if (config.is_open())
    {
        std::cout << "file is open" << std::endl;
    }
    else
    {
        std::cout << "error" << std::endl;
    }
    config >> c_type;
    config >> m;
    config >> n;
    config >> method;
    Coordinate c(c_type, m, n);
    Solver s(c, method);
    config.close();
    return s;
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

    Solver s;
    s = initialization();

    // End measurement
    end = std::chrono::system_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output the result on the console
    // std::cout << s.get_T() << std::endl;
    
    std::cout << "\n elapsed time: " << elapsed_time.count() << "ms\n" << std::endl;


    // ----- write to a csv file -----
    write_to_csv(s.get_T());
}