#pragma once
#include <iostream>
#include "Point3D.h"


class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int pX, int pY) : x{ pX }, y{ pY } {};
	Point& setX(int pX) { x = pX; return *this; }
	Point& setY(int pY) { x = pY; return *this; }
	
	void showPoint()const
	{
		std::cout << "(" << x << ", " << y << ")";
	}

	Point& inputPromt() { cout << "Input point (x,y): "; }

	// перегрузка преобразования в bool
	// operator bool() const { return x || y; }          // если x или y != 0, то вернется true, 
	explicit operator bool() const { return x || y; } 
	
	//operator Point3D() const { return { x, y, 0 }; }; // преобразование точки в точку3D
	operator Point3D() const;

	// дружественные функции
	friend ostream& operator <<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);

	friend Rectangle;
};

