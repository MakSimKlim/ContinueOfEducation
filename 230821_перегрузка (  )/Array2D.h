#pragma once
#include <iostream>
class Array2D
{
	int sizeX;
	int sizeY;
public:
	int** data;

	// массив адресов массивов
	Array2D(int sizeXP, int sizeYP)
		: sizeX{ sizeXP }, sizeY{ sizeYP }, data{ new int* [sizeYP] }
	{
		int* dataElements{ new int[sizeY * sizeX] };// выделение всей памяти одним большим элементом
		for (int i = 0; i < sizeY; ++i)
		{
			data[i] = dataElements + i * sizeX;
		}
	}

	void print() const
	{
		for (int y{ 0 }; y < sizeY; y++)
		{
			for (int x{ 0 }; x < sizeX; x++)
			{
				std::cout << data[y][x] << "\t";
			}
			std::cout << "\n";
		}
	}

	Array2D()
	{
		delete[] data[0];//освобождение памяти из под самих элементов
		delete[] data;   //освобождение памяти самого контейнера
	}

};


