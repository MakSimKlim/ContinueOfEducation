// 230822_преобразование данных
//
// operator typename() {}                // неконстантная функция-член (используется крайне редко)
// operator typename() const {}          // часто применяется, позволяет неявные преобразования
// explicit operator typename() const{}  // часто применяется, позволяет явные преобразования

// Невозможно перегрузить
// :: Оператор расширения области
// .* Операто-указатель на член класса
// . оператор доступа к члену класса
// ?: тернарный оператор

// Если оператор не модифицирует операнды, его лучше перегружать функциями:
// ClassName operator+(const ClassName& left, const ClassName& right);
// ClassName operator+(const ClassName& left, typename right);
// ClassName operator+(typename left, const ClassName& right);

// Дружественные классы (нужны для экономии памяти "супероптимизация")
// class FriendClass (имеет доступ к привату SomeClass)
// {
//
// }
// class SomeClass (не имеет доступ к привату SomeClass)
// {
//  friend FriendClass;
// }


#include <iostream>
#include "Point.h"
#include "Point3D.h"

using namespace std;

void TheoryPrimer1()
{
	int b = 10;
	float a = b;

	if ((bool)a)
	{
		cout << "A!";
	}
}

// Перегрузка оператора вывода дружественными функциями
 ostream& operator<<(ostream& out, const Point& point)
  {
   out << "(" << point.x << ", " << point.y << ")";
   return out;
  }
 // Перегрузка оператора потока ввода дружественными функциями
 istream& operator >> (istream& in, Point& point)
 {
	 in >> point.x >> point.y;
	 return in;
 }


//Point::operator Point3D() const { return { x, y, 0 }; }; // преобразование точки в точку3D
//Point3D::operator Point() const { return { x, y }; }; // преобразование точки3D в точку


int main()
{
	Point p{5, 67};
	cout << "Input coordinates";
	cin >> p;
	// console <- cout, cin
	cout << "Your points is: " << p << "\n"; // передача экземпляра точки внутрь потока
	return 0;

	return 0;
}

void Points()
{
	const int pointCount{ 3 };
	Point points[pointCount]{ {0,0},{28,29},{0,26} };
	bool isNotZero{ false };
	for (int i = 0; i < pointCount; i++)
	{
		Point point = points[i];
		isNotZero = (bool)point;
		if (!isNotZero)
		{
			cout << "Zero Point!\n";
			continue;
		}
		point.showPoint(); cout << endl;
	}

	Point p{ 26,7 };
	Point pConv;

	Point3D p3D{ 24,7,76 };
	Point3D p3DConv;

	pConv = p3D;
	p3DConv = p;

	cout << "Point converted to Point3D: ";
	p3DConv.showPoint3D();

	cout << "Point3D converted to Point: ";
	pConv.showPoint();

}
