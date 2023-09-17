//
// Created by ilia on 17.09.23.
//

#include "../headers/Matrix.hpp"

Matrix::Matrix() {
    rows_ = 0;
    columns_ = 0;
    data_ = nullptr;
}


Matrix::Matrix(int rows, int columns) {
    rows_ = rows;
    columns_ = columns;

    data_ = new float *[rows_]();
    for (int i = 0; i < rows_; i++) {
        data_[i] = new float[columns_]();
    }

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
            data_[i][j] = 0.0f;
        }
    }
}


Matrix::Matrix(const Matrix &other) {
    rows_ = other.rows_;
    columns_ = other.columns_;

    data_ = new float *[rows_]();
    for (int i = 0; i < rows_; i++) {
        data_[i] = new float[columns_]();
    }

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
            data_[i][j] = other.data_[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocate();
}

[[nodiscard]] int Matrix::rows() const {
    return rows_;
}

[[nodiscard]] int Matrix::columns() const {
    return columns_;
}

float &Matrix::operator()(int row, int column) {
    if (row < 0 || row >= rows_ || column < 0 || column >= columns_) {
        throw out_of_range("Index out of range. Matrix &operator()");
    }
    return data_[row][column];
}

float Matrix::operator()(int row, int column) const {
    if (row < 0 || row >= rows_ || column < 0 || column >= columns_) {
        throw out_of_range("Index out of range. Matrix &operator()");
    }
    return data_[row][column];
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }
    Matrix temp(other);
    swap(*this, temp);

    return *this;
}


void Matrix::deallocate() {
    if (data_ != nullptr) {
        for (int i = 0; i < rows_; i++) {
            delete[] data_[i];
        }

        delete[] data_;
        rows_ = 0;
        columns_ = 0;

        data_ = nullptr;
    }
}

void Matrix::swap(Matrix &first, Matrix &second) {
    std::swap(first.rows_, second.rows_);
    std::swap(first.columns_, second.columns_);
    std::swap(first.data_, second.data_);
}
