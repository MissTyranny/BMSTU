#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double eps[] = {1e-2, 1e-4, 1e-6}; // Массив с тремя вариантами точности, которые нужно проверить
    cout << "=== ln(2) = " << log(2.0) << " ===" << endl; // Ну получается точное значение на которое будем ориентироваться
    for (double e:eps) { // Перебор всех элементов eps массива
        cout << "--- eps = " << e << " ---" << endl;

        // Цикл do-while:
        double sum_do = 0.0;
        double term_do;
        int k_do = 0;
        int znak_do = 1;
        do {
            k_do++;
            term_do = 1.0 / k_do;
            sum_do += znak_do * term_do;
            znak_do *= -1; // Знак меняем на противоположный
        } while (term_do >= e); // Цикл идет, пока модуль слагаемого >= варианта точности
        cout << "do-while:  Sum = " << sum_do << " (-_-) Iterations = " << k_do << endl;

        // Цикл while:
        double sum = 0.0;
        double term = 1.0; 
        int k = 0;
        int znak = 1;
        while (term >= e) {
            k++;
            term = 1.0 / k;
            sum += znak * term;
            znak *= -1;
        }
        cout << "while:     Sum = " << sum << " (-_-) Iterations = " << k << endl;

        // Цикл for:
        double sum_for = 0.0;
        int k_for = 0;
        int znak_for = 1;
        for (k_for = 1; (1.0 / k_for) >= e; k_for++) {
            sum_for += znak_for * (1.0 / k_for);
            znak_for *= -1;
        }
        // Так как цикл завершился, когда условие нарушилось (k_for++ выполняется до того), то реальное число учтенных итераций равно (k_for - 1)
        cout << "for:       Sum = " << sum_for << " (-_-) Iterations = " << k_for - 1 << endl;
        cout << endl;
    }
    return 0;
}