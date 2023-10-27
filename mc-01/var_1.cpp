#include <iostream>
#include <cstring>

using namespace std;

bool compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2) < 0;
}

int main() {
    int size;
    cout << "Введите количество книг: ";
    cin >> size;

    cin.ignore(); // очищаем буфер после ввода числа

    char** titles = new char*[size];
    char** authors = new char*[size];
    int* years = new int[size];
    int* copies = new int[size];

    // Ввод информации о книгах
    for (int i = 0; i < size; ++i) {
        cout << "Введите название книги " << i + 1 << ": ";
        char buffer[100];
        cin.getline(buffer, 100);
        titles[i] = new char[strlen(buffer) + 1];
        strcpy(titles[i], buffer);

        cout << "Введите автора книги " << i + 1 << ": ";
        cin.getline(buffer, 100);
        authors[i] = new char[strlen(buffer) + 1];
        strcpy(authors[i], buffer);

        cout << "Введите год издания книги " << i + 1 << ": ";
        cin >> years[i];

        cout << "Введите количество копий книги " << i + 1 << ": ";
        cin >> copies[i];
        cin.ignore(); // очищаем буфер после ввода числа
    }

    // Сортировка книг по названиям в алфавитном порядке (пузырьковая сортировка)
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (compareStrings(titles[j], titles[j + 1])) {
                swap(titles[j], titles[j + 1]);
                swap(authors[j], authors[j + 1]);
                swap(years[j], years[j + 1]);
                swap(copies[j], copies[j + 1]);
            }
        }
    }

    // Вывод списка книг в алфавитном порядке
    cout << "\nСписок книг в библиотеке (отсортированный по названиям):\n";
    for (int i = 0; i < size; ++i) {
        cout << "Название: " << titles[i] << ", Автор: " << authors[i] << ", Год издания: " << years[i] << ", Количество копий: " << copies[i] << endl;
    }

    // Освобождаем выделенную память
    for (int i = 0; i < size; ++i) {
        delete[] titles[i];
        delete[] authors[i];
    }
    delete[] titles;
    delete[] authors;
    delete[] years;
    delete[] copies;

    return 0;
}
