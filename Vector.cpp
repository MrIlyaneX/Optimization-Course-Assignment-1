//
// Created by ilia on 17.09.23.
//

#include "Vector.hpp"

Vector::Vector() {
    size_ = 0;
    real_size_ = 0;
    vector_ = nullptr;
}

Vector::Vector(int vector_size) {
    size_ = vector_size;
    real_size_ = vector_size * 2;

    vector_ = new float[real_size_]();
    for (int i = 0; i < real_size_; i++) {
        vector_[i] = 0.0f;;
    }
}

Vector::Vector(const Vector &other) {
    if (this == &other) {
        return;
    }

    size_ = other.size_;
    real_size_ = other.real_size_;

    vector_ = new float[real_size_]();

    for (int i = 0; i < size_; i++) {
        vector_[i] = other.vector_[i];
    }
}

Vector::~Vector() {
    deallocate();
}

int Vector::size() const {
    return size_;
}

float &Vector::operator[](int index) {
    if (index < 0 || index >= size_) {
        throw out_of_range("Index out of range. Vector &operator[]");
    }
    return vector_[index];
}

float Vector::operator[](int index) const {
    if (index < 0 || index >= size_) {
        throw out_of_range("Index out of range. Vector operator[]");
    }
    return vector_[index];
}

Vector Vector::operator-(Vector &vector) const {
    Vector tmp(*this);
    tmp -= vector;
    return tmp;
}

Vector &Vector::operator-=(Vector &vector) {
    for (int i = 0; i < size_; i++) {
        vector_[i] -= vector[i];
    }
    return *this;
}

Vector Vector::operator*(const float scalar) const {
    Vector tmp(*this);
    tmp *= scalar;
    return tmp;
}

Vector &Vector::operator*=(const float scalar) {
    for (int i = 0; i < size_; i++) {
        vector_[i] *= scalar;
    }
    return *this;
}

Vector Vector::operator/(const float scalar) const {
    Vector tmp(*this);
    tmp /= scalar;
    return tmp;
}

Vector &Vector::operator/=(const float scalar) {
    if (scalar == 0) {
        cerr << "Division by zero is not allowed." << endl;
        return *this;
    }

    for (int i = 0; i < size_; i++) {
        vector_[i] /= scalar;
    }
    return *this;
}

void Vector::resize() {
    int new_size = real_size_ * 2;
    auto *new_vector = new float[new_size]();


    for (int i = 0; i < real_size_; i++) {
        new_vector[i] = vector_[i];
    }
    for (int i = real_size_; i < new_size; i++) {
        new_vector[i] = 0;
    }

    delete[] vector_;
    vector_ = new_vector;
    real_size_ = new_size;
}

Vector &Vector::operator=(Vector other) {
    if (this == &other) {
        return *this;
    }
    Vector temp(other);
    swap(*this, temp);

    return *this;
}


void Vector::deallocate() {
    if (vector_ != nullptr) {

        delete[] vector_;
        size_ = 0;
        real_size_ = 0;

        vector_ = nullptr;
    }
}

void Vector::swap(Vector &first, Vector &second) {
    std::swap(first.vector_, second.vector_);
    std::swap(first.real_size_, second.real_size_);
    std::swap(first.size_, second.size_);
}
