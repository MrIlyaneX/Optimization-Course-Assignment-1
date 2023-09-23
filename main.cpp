#include <iostream>
#include <fstream>

// Custom classes
#include "headers/Matrix.hpp"
#include "headers/Vector.hpp"
#include "headers/SimplexMethod.hpp"

using namespace std;

void check_data_1() {

    Vector b(3), C(3);
    Matrix A(3, 6);
    float accuracy;

    cin >> C >> A >> b >> accuracy;

    SimplexMethod::start_simplex(A, b, C, accuracy);
}


int main() {

    check_data_1();

    return EXIT_SUCCESS;
}
