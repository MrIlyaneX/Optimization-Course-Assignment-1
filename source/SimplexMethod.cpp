//
// Created by ilia on 17.09.23.
//

#include "../headers/SimplexMethod.hpp"

// to check signs of numbers (since floating point numbers could work badly with <= or ==)
#include <cmath>

int SimplexMethod::define_pivot_col(Vector &net_eval) {
    float mx = net_eval[0];
    int index = -1;
    for (int i = 0; i < net_eval.size(); ++i) {
        if (islessequal(mx, net_eval[i])) {
            mx = net_eval[i];
            index = i;
        }
    }
    return index;
}

Vector SimplexMethod::calculate_ratio(Matrix &main_matrix, int &pivot_col, const float accuracy) {
    if (pivot_col == -1) {
        cout << "No pivot column\n:main_matrix:\n" << main_matrix;
        exit(10);
    }
    Vector pivot_column = main_matrix.getCol(pivot_col);
    Vector ans = main_matrix.getCol(main_matrix.columns() - 1);

    for (int i = 0; i < pivot_column.size(); ++i) {
        if (isgreater(abs(ans[i]), 0) && isgreater(abs(pivot_column[i]), 0.00f)) {
            ans[i] = ans[i] / pivot_column[i];
            ans[i] = rounding(accuracy, ans[i]);
            continue;
        }
        ans[i] = -1.0;
    }
    return ans;
}

int SimplexMethod::define_pivot_row(Vector &ratio) {
    float ans = ratio[0];
    int index = -1;
    for (int i = 0; i < ratio.size(); ++i) {
        if (signbit(ratio[i])) continue;
        if (islessequal(ratio[i], ans)) {
            ans = ratio[i];
            index = i;
        }
    }
    return index;
}

float SimplexMethod::define_pivot_element(Matrix &main_matrix, int &pivot_col, int &pivot_row) {
    return main_matrix(pivot_row, pivot_col);
}

Vector SimplexMethod::define_basis(Vector &basis, int &pivot_row, int &pivot_col, Vector &function_coefficients) {
    basis[pivot_row] = function_coefficients[pivot_col];
    return basis;
}

Matrix
SimplexMethod::update_main_matrix(Matrix &main_matrix, int &pivot_row, int &pivot_col, float pivot_element,
                                  const float accuracy) {
    Matrix new_matrix = main_matrix;
    Vector new_pivot_row = main_matrix.getRow(pivot_row) / pivot_element;
    new_pivot_row = rounding(accuracy, new_pivot_row);

    new_matrix.setRow(pivot_row, new_pivot_row);
    for (int i = 0; i < main_matrix.rows(); ++i) {
        if (i == pivot_row) continue;
        auto buf = new_matrix.getRow(pivot_row) * main_matrix(i, pivot_col);
        buf = main_matrix.getRow(i) - buf;
        new_matrix.setRow(i, buf);
    }

    new_matrix = rounding(accuracy, new_matrix);

    return new_matrix;
}

Vector SimplexMethod::define_basis_element(Vector &basis, Vector &basis_el, int &pivot_row, int &pivot_col) {
    basis_el[pivot_row] = pivot_col + 1;
    return basis_el;
}

Vector SimplexMethod::calculate_profit(Matrix &main_matrix, Vector &basis, const float accuracy) {
    Vector temp = main_matrix.transpose() * basis;
    return rounding(accuracy, temp);
}

Vector SimplexMethod::calculate_net_evaluation(Vector &function_coefficients, Vector &profit) {
    Vector ans = (function_coefficients - profit);
    return rounding(0.1, ans);
}

bool SimplexMethod::check_net_evaluation(Vector &net_eval) {
    for (int i = 0; i < net_eval.size() - 1; ++i) {
        if (!islessequal(net_eval[i], 0.f)) return false;
    }
    return true;
}

void SimplexMethod::start_simplex(const Matrix &A, const Vector &B, const Vector &C, const float accuracy) {
    check_feasibility(A, B, C, accuracy);


    Matrix main_matrix;
    Vector func_coefficients;

    Vector net_eval;
    initialize_algorithm_data(A, B, C, main_matrix, func_coefficients, net_eval);
    Vector basis(main_matrix.rows(), 0.0f);
    Vector profit(main_matrix.columns(), 0.0f);
    Vector basis_el(main_matrix.rows(), 0.0f);
    Vector ratio(main_matrix.rows(), 0.0f);


    for (int i = 0; i < A.rows(); ++i) {
        int pivot_col = define_pivot_col(net_eval);
        ratio = calculate_ratio(main_matrix, pivot_col, accuracy);
        int pivot_row = define_pivot_row(ratio);
        float pivot_el = define_pivot_element(main_matrix, pivot_col, pivot_row);
        basis = define_basis(basis, pivot_row, pivot_col, func_coefficients);
        basis_el = define_basis_element(basis, basis_el, pivot_row, pivot_col);
        main_matrix = update_main_matrix(main_matrix, pivot_row, pivot_col, pivot_el, accuracy);
        profit = calculate_profit(main_matrix, basis, accuracy);
        net_eval = calculate_net_evaluation(func_coefficients, profit);

        cout << "\n:main_matrix:\n" << main_matrix << ":profit:\n" << profit << ":net_eval:\n" << net_eval << "\n\n";
        if (check_net_evaluation(net_eval)) break;
    }
    for (int i = 0; i < basis.size(); ++i) {
        if (basis_el[i] != 0) cout << "x_" << basis_el[i] << " = " << main_matrix(i, main_matrix.columns()-1) << "\n";
    }
    cout << "Profit = " << profit[profit.size() - 1] << "\n" << profit;
}

// parser of initial vectors
// Assumptions that Matrix A contains coefficients of the slack\artificial variables
void SimplexMethod::initialize_algorithm_data(const Matrix &A, const Vector &B, const Vector &C, Matrix &main_matrix,
                                              Vector &func_coefficients, Vector &net_eval) {


    main_matrix = Matrix(A.rows(), A.columns() * 2 + 1);
    func_coefficients = Vector(main_matrix.columns() - 1, 0.0f);
    for (int i = 0; i < A.rows(); ++i) {
        for (int j = 0; j < A.columns(); ++j) {
            main_matrix(i, j) = A(i, j);
        }
        main_matrix(i, A.columns() + i) = 1.0000f;
    }

    for (int i = 0; i < C.size(); ++i) {
        func_coefficients[i] = C[i];
    }
    net_eval = func_coefficients;

    for (int i = 0; i < B.size(); ++i) {
        main_matrix(i, main_matrix.columns() - 1) = B[i];
    }

    cout << "Check of initial data data:\n" << main_matrix << ":coefficients:\n" << func_coefficients << ":net_eval:\n"
         << net_eval << "\n";
}

// rounds the numbers using given epsilon, should work with small epsilon
float SimplexMethod::rounding(float epsilon, float variable) {
    float roundedValue = roundf(variable / epsilon) * epsilon;
    return roundedValue;
}

Vector SimplexMethod::rounding(float epsilon, Vector &variable) {
    Vector rounded_vector(variable.size());
    for (int i = 0; i < variable.size(); ++i) {
        rounded_vector[i] = rounding(epsilon, variable[i]);
    }
    return rounded_vector;
}

Matrix SimplexMethod::rounding(float epsilon, Matrix &variable) {
    Matrix rounded_matrix(variable.rows(), variable.columns());
    for (int i = 0; i < variable.rows(); ++i) {
        for (int j = 0; j < variable.columns(); ++j) {
            rounded_matrix(i, j) = rounding(epsilon, variable(i, j));
        }
    }
    return rounded_matrix;
}


void SimplexMethod::check_feasibility(const Matrix &A, const Vector &B, const Vector &C, float epsilon) {
    for (int i = 0; i < B.size(); ++i) {
        if (isless(B[i], epsilon - epsilon)) {
            cout << "Infeasible solution: Wrong input for vector B";
        }
    }
}
