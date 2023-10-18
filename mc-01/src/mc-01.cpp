#include <iostream>
#include <cstring>


using namespace std;

int main() {
    int size;
    cout << "Введите количество студентов: ";
    cin >> size;

    // Выделяем динамические массивы для имен и возрастов студентов
    char** names = new char*[size];
    int* ages = new int[size];

    cin.ignore(); // очищаем буфер после ввода числа

    // Ввод имен и возрастов студентов
    for (int i = 0; i < size; ++i) {
        cout << "Введите имя студента " << i + 1 << ": ";
        char buffer[100];
        cin.getline(buffer, 100);
        names[i] = new char[strlen(buffer) + 1];
        strcpy(names[i], buffer);

        cout << "Введите возраст студента " << i + 1 << ": ";
        cin >> ages[i];
        cin.ignore(); // очищаем буфер после ввода числа
    }

    // Сортировка студентов по алфавиту
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                swap(names[j], names[j + 1]);
                swap(ages[j], ages[j + 1]);
            }
        }
    }

    // Вывод отсортированного списка студентов
    cout << "\nОтсортированный список студентов:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Имя: " << names[i] << ", Возраст: " << ages[i] << endl;
    }

    // Поиск студента по имени
    char searchName[100];
    cout << "\nВведите имя студента для поиска: ";
    cin.getline(searchName, 100);

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(names[i], searchName) == 0) {
            cout << "Возраст студента " << searchName << ": " << ages[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Студент с именем " << searchName << " не найден." << endl;
    }

    // Освобождаем выделенную память
    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }
    delete[] names;
    delete[] ages;

    return 0;
}
