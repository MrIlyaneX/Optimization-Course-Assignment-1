//
// Created by ilia on 17.09.23.
//

#include <iostream>
#include <cassert>

// Custom classes
#include "Vector.hpp"
#include "Matrix.hpp"
#include "SimplexMethod.hpp"

using namespace std;


bool testVector();

bool testMatrix();

bool testSimplexMethod();

int main() {
    cout << "Vector testing:\n";
    bool t1 = testVector();
    cout << "results: " << bool(t1) << "\n";

    cout << "Matrix testing:\n";
    bool t2 = testMatrix();
    cout << "results: " << bool(t2) << "\n";

    cout << "SimplexMethod testing:\n";
    bool t3 = testSimplexMethod();
    cout << "results: " << bool(t3) << "\n";

    return EXIT_SUCCESS;
}

bool testVector() {

    Vector v1;
    if (v1.size() == 0) {
        cout << "\tDefault Constructor Test Passed" << endl;
    } else {
        cerr << "\tDefault Constructor Test Failed" << endl;
    }

    Vector v2(5);
    if (v2.size() == 5) {
        cout << "\tConstructor with Size Test Passed" << endl;
    } else {
        cerr << "\tConstructor with Size Test Failed" << endl;
    }

    Vector v3(v2);
    if (v3.size() == 5) {
        cout << "\tCopy Constructor Test Passed" << endl;
    } else {
        cerr << "\tCopy Constructor Test Failed" << endl;
    }


    v3[0] = 10.0;
    v3[1] = 20.0;
    if (v3[0] == 10.0 && v3[1] == 20.0) {
        cout << "\tIndexing and Modification Test Passed" << endl;
    } else {
        cerr << "\tIndexing and Modification Test Failed" << endl;
    }


    Vector v4(2);
    v4[0] = 1.0;
    v4[1] = 2.0;

    Vector result = v3 - v2;
    if (result[0] == 10.0 && result[1] == 20.0) {
        cout << "\tVector Subtraction Test Passed" << endl;
    } else {
        cerr << "\tVector Subtraction Test Failed" << endl;
    }

    result *= 2.0;
    if (result[0] == 20.0 && result[1] == 40.0) {
        cout << "\tScalar Multiplication Test Passed" << endl;
    } else {
        cerr << "\tScalar Multiplication Test Failed" << endl;
    }

    result /= 2.0;
    if (result[0] == 10.0 && result[1] == 20.0) {
        cout << "\tScalar Division Test Passed" << endl;
    } else {
        cerr << "\tScalar Division Test Failed" << endl;
    }
    return true;
}


bool testMatrix() {
    Matrix mat1;
    if (mat1.rows() == 0 && mat1.columns() == 0) {
        cout << "\tDefault constructor test passed." << endl;
    } else {
        cerr << "\tDefault constructor test failed." << endl;
    }


    Matrix mat2(3, 4);
    if (mat2.rows() == 3 && mat2.columns() == 4) {
        cout << "\tConstructor with dimensions test passed." << endl;
    } else {
        cerr << "\tConstructor with dimensions test failed." << endl;
    }


    mat2(0, 0) = 1.0;
    mat2(1, 1) = 2.0;
    if (mat2(0, 0) == 1.0 && mat2(1, 1) == 2.0) {
        cout << "\tElement access and assignment test passed." << endl;
    } else {
        cerr << "\tElement access and assignment test failed." << endl;
    }


    Matrix mat3(mat2);
    if (mat3.rows() == 3 && mat3.columns() == 4 && mat3(0, 0) == 1.0 && mat3(1, 1) == 2.0) {
        cout << "\tCopy constructor test passed." << endl;
    } else {
        cerr << "\tCopy constructor test failed." << endl;
    }

    Matrix mat4;
    mat4 = mat3;
    if (mat4.rows() == 3 && mat4.columns() == 4 && mat4(0, 0) == 1.0 && mat4(1, 1) == 2.0) {
        cout << "\tAssignment operator test passed." << endl;
    } else {
        cerr << "\tAssignment operator test failed." << endl;
    }


    if (mat2.rows() == 3 && mat2.columns() == 4) {
        cout << "\tMatrix dimensions test passed." << endl;
    } else {
        cerr << "\tMatrix dimensions test failed." << endl;
    }


    bool assertionThrown = false;
    try {
        float value = mat2(5, 5);
    } catch (const out_of_range &e) {
        assertionThrown = true;
    }

    if (assertionThrown) {
        cout << "\tOut-of-range access test passed (assertion thrown)." << endl;
    } else {
        cerr << "\tOut-of-range access test failed (assertion not thrown)." << endl;
    }
    return true;
}

bool testSimplexMethod() {
    return true;
}