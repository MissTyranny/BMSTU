#pragma once
#include <iostream>
 
class Vector {
private:
    int* p;
    int n;
 
public:
    Vector();
    Vector(const int* arr, int size);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();
 
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
 
    int& operator[](int index);
    Vector operator--(int);
 
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};