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
void getValue(string promt, T& value)
{
	cout << promt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... Try again\n";

		cout << promt;
		cin >> value;


	}
	// извлечение символа Enter из последней строчки
	string endLine;
	getline(cin, endLine);

}