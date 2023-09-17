//
// Created by ilia on 17.09.23.
//

#include "../headers/SimplexMethod.hpp"


int SimplexMethod::define_pivot_col(Vector &net_eval) {
    return 0;
}

Vector SimplexMethod::calculate_ratio(Matrix &main_matrix, Vector &pivot_col) {
    return Vector();
}

float SimplexMethod::define_pivot_row(Vector &ratio) {
    return 0;
}

float SimplexMethod::define_pivot_element(Matrix &main_matrix, Vector &pivot_col, Vector &pivot_row) {
    return 0;
}

Vector SimplexMethod::define_basis(Vector &basis, Vector &pivot_row, Vector &piwvt_col, Vector &function_coefficients) {
    return Vector();
}

Matrix
SimplexMethod::update_main_matrix(Matrix &main_matrix, Vector &pivot_row, Vector &pivot_col, float pivot_element) {
    return Matrix();
}

Vector SimplexMethod::define_basis_element(Vector &basis, Vector &pivot_row, Vector &pivot_col) {
    return Vector();
}

Vector SimplexMethod::calculate_profit(Matrix &main_matrix, Vector &basis) {
    return Vector();
}

Vector SimplexMethod::calculate_net_evaluation(Vector &function_coefficients, Vector &profit) {
    return Vector();
}

bool SimplexMethod::check_net_evaluation(Vector &net_eval) {
    return false;
}