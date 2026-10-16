#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Disciplina {
    string name;  // Предмет
    int grade;    // Оценка
};
struct Student {
    string fio;                  // ФИО
    vector<Disciplina> subjects; // Массив элементов структуры "дисциплина"
};
void input_student(Student &s) {
    cout << "ФИО студента: ";
    getline(cin, s.fio);
    int count = 4; // Пусть будет ровно 4 элемента
    s.subjects.resize(count);
    for (int i = 0; i < count; i++) {
        cout << "  Название предмета " << i + 1 << ": ";
        getline(cin, s.subjects[i].name);
        cout << "  Оценка по предмету (от 2 до 5): ";
        cin >> s.subjects[i].grade;
        cin.ignore(); // Очистка буфера перед вводом строк
    }
}
void print_student(const Student &s) {
    cout << "Студент: " << s.fio << endl;
    for (int i = 0; i < s.subjects.size(); i++) {
        cout << "  - " << s.subjects[i].name << ": " << s.subjects[i].grade << endl;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество студентов (n): ";
    cin >> n;
    cin.ignore(); // Очистка буфера перед вводом строк
    vector<Student> group(n);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Ввод данных для студента №" << i + 1 << " ---\n";
        input_student(group[i]);
    }

    cout << "\n=== Контрольный вывод данных группы ===\n";
    for (int i = 0; i < n; i++) {
        print_student(group[i]);
        cout << "--------------------------------------------\n";
    }

    // Наконец, решение задачи (мой вариант 7):
    // "Определите, какое количество неудовлетворительных оценок получено по всем предметам"
    int bad_ocenka_count = 0;
    // Перебор каждого студента в группе
    for (int i = 0; i < n; i++) {
        // Перебор каждого предмета у конкретного студента
        for (int j = 0; j < group[i].subjects.size(); j++) {
            if (group[i].subjects[j].grade <= 2) {
                bad_ocenka_count++;
            }
        }
    }
    // Вывод итогового результата
    cout << "\nРезультат. Всего неудовлетворительных оценок в группе: " << bad_ocenka_count << endl;

    return 0;
}