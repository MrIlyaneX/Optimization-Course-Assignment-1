//
// Created by ilia on 17.09.23.
//

#ifndef OPTIMIZATION_COURSE_ASSIGNMENT_1_VECTOR_HPP
#define OPTIMIZATION_COURSE_ASSIGNMENT_1_VECTOR_HPP


#include <iostream>

using namespace std;


class Vector {
public:
    Vector();

    explicit Vector(int vector_size);

    Vector(const Vector &other);

    ~Vector();

    [[nodiscard]] int size() const;

    float &operator[](int index);

    float operator[](int index) const;

    Vector operator-(Vector &vector) const;

    Vector &operator-=(Vector &vector);

    Vector operator*(float scalar) const;

    Vector &operator*=(float scalar);

    Vector operator/(float scalar) const;

    Vector &operator/=(float scalar);

    Vector &operator=(Vector other);

private:
    int size_, real_size_;

    float *vector_;

    // resize function since the standard arrays used for storing data
    void resize();

    void deallocate();

    static void swap(Vector &first, Vector &second);
};


#endif //OPTIMIZATION_COURSE_ASSIGNMENT_1_VECTOR_HPP
