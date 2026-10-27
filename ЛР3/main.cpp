#include <iostream>
#include <fstream>
#include <clocale> 
#include "Vector.h"
 
int main() {
    std::setlocale(LC_ALL, "Russian");
 
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");
 
    Vector v1;
    infile >> v1;
 
    outfile << "Вектор v1: " << v1 << std::endl;
 
    Vector v2 = v1--;
    outfile << "Вектор v2 (результат v1--): " << v2 << std::endl;
    outfile << "Вектор v1 после уменьшения: " << v1 << std::endl;
 
    Vector v3;
    v3 = std::move(v1);
    outfile << "Вектор v3 (после перемещения из v1): " << v3 << std::endl;
 
    return 0;
}