// 230824_полиморфизм.
//
// Два вида полиморфизма: статический(полиморфизм времени компиляции), динамический(полиморфизм времени выполнения)
// 
// статический полиморфизм (виды реализации): 
// - перегрузка функции
// - перегрузка оператора
// - шаблоны (обобщенное описание)
//
//



#include <iostream>
#include <string>
#include"ArrayFunctions.h"

using namespace std;

//// Пример полиморфизма (перегрузка функции), когда вызывается одно слово, но выполняет оно разные действия
//void sort(int* Array, int size); // прототип функции сортировки (интерфейс функции)
//void sort(double* Array, int size); // прототип функции сортировки
//void sort(string* Array, int size); // прототип функции сортировки


//шаблоны
// template <template-parameter-list> function-declaration
// class typename - для ООП они взаимозаменяемы
// typename - для процедурного программирования
// Т - изменяемый тип данных

template <class T>
T square(T number)
{
	T res = number * number;
	return res;
}
// template <template-parameter-list> class-declaration
template <class T>
class DArray
{
	T* data;
	size_t size;
};



int main()
{
	//square(5);
	//square(3.4);

	int intAr[]{ 1,2,3,4,5 };
	int size = sizeof(intAr) / sizeof(int);
	cout << "Original array:";
	display<int>(intAr, size);
	sort<int>(intAr, size);
	cout << "Sorted array:";
	display<int>(intAr, size);
	
	char charAr[]{ 'o','t','f','f','s', 'a','n'};
	size = sizeof(charAr) / sizeof(char);
	cout << "Original array:";
	display<char>(charAr, size);
	sort<char>(charAr, size);
	cout << "Sorted array:";
	display<char>(charAr, size);

	int A;
	getValue("Enter number: ", A);
	cout << A << endl;

	string name;
	getValue("Enter your name:", name);
	cout << name << endl;


	return 0;
}

