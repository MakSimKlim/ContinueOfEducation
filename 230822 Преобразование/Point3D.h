#pragma once
#include <iostream>
#include "Point.h"


class Point3D
{
	int x;
	int y;
	int z;
public:
	Point3D() = default;
	Point3D(int pX, int pY, int pZ) : x{ pX }, y{ pY }, z{ pZ } {};
	Point3D& setX(int pX) { x = pX; return *this; }
	Point3D& setY(int pY) { x = pY; return *this; }
	Point3D& setZ(int pZ) { x = pZ; return *this; }


	void showPoint3D() const
	{
		std::cout << "(" << x << ", " << y << ", " << z << ")";
	}
	// ���������� �������������� � bool
	// operator bool() const { return x || y || z; }          // ���� x, y ��� z != 0, �� �������� true, 
	explicit operator bool() const { return x || y || z; }

	//operator Point() const { return { x, y }; }; // �������������� �����3D � �����
	operator Point() const;



};

