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


private:

    int define_pivot_col(Vector &net_eval);

    Vector calculate_ratio(Matrix &main_matrix, Vector &pivot_col);

    float define_pivot_row(Vector &ratio);

    float define_pivot_element(Matrix &main_matrix, Vector &pivot_col, Vector &pivot_row);

    Vector define_basis(Vector &basis, Vector &pivot_row, Vector &piwvt_col, Vector &function_coefficients);

    Matrix update_main_matrix(Matrix &main_matrix, Vector &pivot_row, Vector &pivot_col, float pivot_element);

    Vector define_basis_element(Vector &basis, Vector &pivot_row, Vector &pivot_col);

    Vector calculate_profit(Matrix &main_matrix, Vector &basis);

    Vector calculate_net_evaluation(Vector &function_coefficients, Vector &profit);

    bool check_net_evaluation(Vector &net_eval);

};

#endif //OPTIMIZATION_COURSE_ASSIGNMENT_1_SIMPLEXMETHOD_HPP
