//
// Created by ilia on 17.09.23.
//

#ifndef OPTIMIZATION_COURSE_ASSIGNMENT_1_MATRIX_HPP
#define OPTIMIZATION_COURSE_ASSIGNMENT_1_MATRIX_HPP

#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix();

    Matrix(int rows, int columns);

    Matrix(const Matrix &other);

    ~Matrix();

    [[nodiscard]] int rows() const;

    [[nodiscard]] int columns() const;

    float &operator()(int row, int column);

    float operator()(int row, int column) const;

    Matrix &operator=(const Matrix &other);

    // You can add more operations and methods as needed for your use case

private:
    int rows_;
    int columns_;
    float **data_;

    void deallocate();

    static void swap(Matrix &first, Matrix &second);
};


#endif //OPTIMIZATION_COURSE_ASSIGNMENT_1_MATRIX_HPP
