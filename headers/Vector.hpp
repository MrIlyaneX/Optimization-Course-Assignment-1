//
// Created by ilia on 17.09.23.
//

#ifndef OPTIMIZATION_COURSE_ASSIGNMENT_1_VECTOR_HPP
#define OPTIMIZATION_COURSE_ASSIGNMENT_1_VECTOR_HPP


#include <iostream>
#include <vector>


using namespace std;


class Vector {
public:
    Vector();

    explicit Vector(int vector_size, float initial_value = 0.0f);

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

    //overloaded ostream operator
    friend std::ostream &operator<<(std::ostream &os, const Vector &item) {
        for (int i = 0; i < item.size(); ++i) {
            os << item[i] << " ";
        }
        cout << "\n";
        return os;
    }

    //overloaded istream operator
    friend std::istream &operator>>(std::istream &input_stream, Vector &item) {
        for (int i = 0; i < item.size(); ++i) {
            input_stream >> item[i];
        }
        if (!input_stream) {
            throw std::runtime_error("Invalid input (matrix input error)\n");
        }
        return input_stream;
    }

private:
    vector<float> vector_;

    // resize function since the standard arrays used for storing data
    void resize();


    static void swap(Vector &first, Vector &second);
};


#endif //OPTIMIZATION_COURSE_ASSIGNMENT_1_VECTOR_HPP
