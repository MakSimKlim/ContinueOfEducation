#include <iostream>
#pragma once
class Matrix
{
	int sizeX;
	int sizeY;
	int* data;

	// приватные методы
	int index2D(int y, int x)const
	{
		return y * sizeX + x;
	}

	int index2D(int y, int x, int sizeXP) const
	{
		return y * sizeXP + x;
	}
public:
	Matrix(int sizeYP, int sizeXP)
		:sizeY{ sizeYP }, sizeX{sizeXP},
		data{new int[sizeYP*sizeXP]}
	{}

	int operator()(int y, int x)
	{
		return *(data + index2D(y, x));// * разыменование адреса
	}

	int& operator()(int y, int x)
	{
		return *(data + index2D(y, x));
	}
	void deleteColumn(int colPos)
	{
		--sizeX;
		int* newData{ new int[sizeY * sizeX] };
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				*(newData + index2D(y, x)) = *(data + index2D(y, x + (x >= colPos)));
			}

		}
		delete[] data;
		data = newData;
	
	}

	void addColumn(int columnPos, int* newCol = nullptr)
	{
		int* newData{ new int[sizeY * (sizeX + 1)] };
		for (int y{ 0 }; y < sizeY; y++)
		{
			for (int x{ 0 }; x < sizeX; x++)
			{
				*(newData + index2D(y, x + (x >= columnPos), sizeX + 1)) = *(data + index2D(y, x));
					
			}
			*(newData + index2D(y, columnPos, sizeX+1)) = newCol ? *(newCol + y) : 0;
		}
		delete[] data;
		data = newData;
		++sizeX;
	}
	void print() const
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int x = 0; x < sizeX; x++)
			{
				std::cout << (*this)(y, x) << "\t";
			}
			std::cout << "\n";

		}
	
	}
	~Matrix() { delete[] data; }
};

