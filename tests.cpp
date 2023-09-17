//
// Created by ilia on 17.09.23.
//

#include <iostream>
#include <cassert>

// Custom classes
#include "headers/Vector.hpp"
#include "headers/Matrix.hpp"
#include "headers/SimplexMethod.hpp"

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
    {
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
    }
    cout << "\t New phase:\n";
    {
        Matrix mat(3, 3);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat(i, j) = i * 3 + j + 1;
            }
            cout << endl;
        }


        Vector vector(3);
        vector[0] = 1.0;
        vector[1] = 2.0;
        vector[2] = 3.0;

        Matrix result = mat * vector;
        assert(result.rows() == 3);
        assert(result.columns() == 1);
        assert(result(0, 0) == 14.0);
        assert(result(1, 0) == 32.0);
        assert(result(2, 0) == 50.0);


        Matrix mat2(mat);
        mat2 *= vector;
        assert(mat2.rows() == 3);
        assert(mat2.columns() == 1);
        assert(mat2(0, 0) == 14.0);
        assert(mat2(1, 0) == 32.0);
        assert(mat2(2, 0) == 50.0);


        Vector row = mat.getRow(1);
        assert(row.size() == 3);
        assert(row[0] == 4.0);
        assert(row[1] == 5.0);
        assert(row[2] == 6.0);

        Vector newRow(3);
        newRow[0] = 7.0;
        newRow[1] = 8.0;
        newRow[2] = 9.0;
        mat.setRow(1, newRow);
        assert(mat(1, 0) == 7.0);
        assert(mat(1, 1) == 8.0);
        assert(mat(1, 2) == 9.0);


        Vector col = mat.getCol(2);
        assert(col.size() == 3);
        assert(col[0] == 3.0);
        assert(col[1] == 9.0);
        assert(col[2] == 9.0);

        Vector newCol(3);
        newCol[0] = 10.0;
        newCol[1] = 11.0;
        newCol[2] = 12.0;
        mat.setCol(2, newCol);
        assert(mat(0, 2) == 10.0);
        assert(mat(1, 2) == 11.0);
        assert(mat(2, 2) == 12.0);


        Matrix transposed = mat.transpose();
        assert(transposed.rows() == mat.columns());
        assert(transposed.columns() == mat.rows());
        assert(transposed(0, 0) == mat(0, 0));
        assert(transposed(0, 1) == mat(1, 0));
        assert(transposed(0, 2) == mat(2, 0));
    }
    return true;
}

bool testSimplexMethod() {
    return true;
}