#include "Vector.h"
 
Vector::Vector() {
    p = nullptr;
    n = 0;
}
 
Vector::Vector(const int* arr, int size) {
    n = size;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = arr[i];
    }
}
 
Vector::Vector(const Vector& other) {
    n = other.n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = other.p[i];
    }
}
 
Vector::Vector(Vector&& other) noexcept {
    p = other.p;
    n = other.n;
    other.p = nullptr;
    other.n = 0;
}
 
Vector::~Vector() {
    if (p != nullptr) {
        delete[] p;
    }
}
 
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] p;
        n = other.n;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = other.p[i];
        }
    }
    return *this;
}
 
Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] p;
        p = other.p;
        n = other.n;
        other.p = nullptr;
        other.n = 0;
    }
    return *this;
}
 
int& Vector::operator[](int index) {
    return p[index];
}
 
Vector Vector::operator--(int) {
    Vector temp(*this);
    for (int i = 0; i < n; i++) {
        p[i] -= 1;
    }
    return temp;
}
 
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << vec.n << " ";
    for (int i = 0; i < vec.n; i++) {
        os << vec.p[i] << " ";
    }
    return os;
}
 
std::istream& operator>>(std::istream& is, Vector& vec) {
    int size;
    if (is >> size) {
        delete[] vec.p;
        vec.n = size;
        vec.p = new int[vec.n];
        for (int i = 0; i < vec.n; i++) {
            is >> vec.p[i];
        }
    }
    return is;
}