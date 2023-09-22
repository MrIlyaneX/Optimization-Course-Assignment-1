//
// Created by ilia on 17.09.23.
//

#ifndef OPTIMIZATION_COURSE_ASSIGNMENT_1_SIMPLEXMETHOD_HPP
#define OPTIMIZATION_COURSE_ASSIGNMENT_1_SIMPLEXMETHOD_HPP


#include "Vector.hpp"
#include "Matrix.hpp"

using namespace std;

class SimplexMethod {
public:

    static void start_simplex(Vector &A, Vector &B, Vector &C);


private:

    static void initialize_algorithm_data(const Vector &A, const Vector &B, const Vector &C, Matrix &main_matrix,
                                          Vector &func_coefficients,
                                          Vector &basis, Vector &profit,
                                          Vector &basis_el, Vector &net_eval);

    static int define_pivot_col(Vector &net_eval);

    static Vector calculate_ratio(Matrix &main_matrix, int &pivot_col);

    static int define_pivot_row(Vector &ratio);

    static float define_pivot_element(Matrix &main_matrix, int &pivot_col, int &pivot_row);

    static Vector define_basis(Vector &basis, int &pivot_row, int &pivot_col, Vector &function_coefficients);

    static Matrix update_main_matrix(Matrix &main_matrix, int &pivot_row, int &pivot_col, float pivot_element);

    static Vector define_basis_element(Vector &basis, Vector &basis_el, int &pivot_row, int &pivot_col);

    static Vector calculate_profit(Matrix &main_matrix, Vector &basis);

    static Vector calculate_net_evaluation(Vector &function_coefficients, Vector &profit);

    static bool check_net_evaluation(Vector &net_eval);

};

#endif //OPTIMIZATION_COURSE_ASSIGNMENT_1_SIMPLEXMETHOD_HPP
