#include <iostream>
#include <fstream>

// Custom classes
#include "headers/SimplexMethod.hpp"

using namespace std;

void check_data_1() {

    int num_func_var, rows, columns;
    //cout << "Enter number of variables in objective function: ";
    cin >> num_func_var;
    //cout << "Enter number of inequalities in constraint and number of variables in it: ";
    cin >> rows >> columns;

    Vector b(rows), C(num_func_var);
    Matrix A(rows, columns);
    float accuracy;

    cin >> C >> A >> b >> accuracy;

    SimplexMethod::start_simplex(A, b, C, accuracy);
}


int main() {

    check_data_1();

    return EXIT_SUCCESS;
}
