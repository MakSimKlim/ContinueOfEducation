#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void sort(T array[], size_t size)
{
	for (int k = size - 1; k > 0; k--)
	{
		for (int j = 0; j < k; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}

template <class T>
void display(T array[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template <class T>
void getValue(string prompt, T& value)
{
	cout << prompt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... Try again\n";

		cout << prompt;
		cin >> value;


	}
	// извлечение символа Enter из последней строчки
	string endLine;
	getline(cin, endLine);

}

// механизм специализации
template<>
void getValue<string>(string prompt, string& value)
{
	cout << prompt;
	getline(cin, value);

}
// специализаци€ объ€вл€етс€ только после объ€влени€ общего шаблона
// 
// полна€ сепциализаци€ 
// template <> className<dataTypeList>{classDefinition}