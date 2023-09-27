// ДЗ #13 до 28.09.23_аргументы командной строки
//
// Задание 1. Программа принимает в качестве аргумента командной строки (ни
//в коем случае не вводом через поток cin) путь к текстовому файлу.Затем
//программа выводит на экран его содержимое.

#define _CRT_SECURE_NO_WARNINGS 0; 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
    setlocale(LC_ALL,"Rus");
    // Проверяем, передан ли путь к файлу в аргументах командной строки
    if (argc != 2) {
        cerr << "Использование: " << argv[0] << " <путь_к_файлу>" << endl;
        return 1; // Возвращаем код ошибки
    }

    // Открываем файл
    ifstream file(argv[1]);

    // Проверяем, успешно ли открыт файл
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << argv[1] << endl;
        return 1; // Возвращаем код ошибки
    }

    // Читаем файл построчно и выводим на экран
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Закрываем файл
    file.close();

    return 0; // Возвращаем успешный код завершения
}


