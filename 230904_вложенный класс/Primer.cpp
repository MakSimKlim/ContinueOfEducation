// пример множественного наследования

#include <iostream>

using namespace std;

class Car
{
protected:
	int wheels;
	double currentVelocity;
	double maxVelocity;
public:
	Car(int wheelsP, double maxVelocityP)
		: wheels{ wheelsP }, maxVelocity{ maxVelocityP }, currentVelocity{0}
	{}

	Car() : Car{ 0,0 } {}

	void AccellerateBy(double delta)
	{
		currentVelocity += delta;
		if (currentVelocity < 0) currentVelocity = 0;
		if (currentVelocity > maxVelocity) currentVelocity = maxVelocity;
	}

	void Show()
	{
		cout << "This" << wheels << "wheeler is going at ";
		cout << currentVelocity << "km/h\n";
	}
};

class Container
{
protected:
	string content;
	double weight;
	double maxWeight;

public:
	Container(string c, double mw)
		: content{ c }, maxWeight{ mw }, weight{0}
	{}

	Container() : Container("", 0) {}

	void ChangeContent(string c)
	{
		content = c;
		weight = 0;
	}

	void LoadMore(double delta)
	{
		weight += delta;
		if (weight < 0) weight = 0;
		if (weight > maxWeight) weight = maxWeight;
	}

	void LookInside()
	{
		cout << "There is " << weight << "kr of" << content << "inside!\n";
	}
};

class Truck: public Car, public Container
{
public:
	Truck(int  wheelsP, int maxVelocityP, string contentP, double maxWeight) :
		Car{wheelsP, maxVelocityP}, Container{contentP, maxWeight}
	{}

	Truck() : Car{0,0}, Container{"", 0}{}
	void Display()
	{
	Show();
	LookInside();
	}
};

template<class T>
class Couple
{
protected:
	T a;
	T b;
public:
	Couple(T t1, T t2) : a{ t1 }, b{ t2 } {};
	friend ostream& operator << (ostream& out, Couple c)
	{
		out << c.a << " " << c.b;
		return out;
	
	}


};

template<class T>
class Trio : Couple<T>
{
protected:
	T c;
public:
	Trio(T t1, T t2, T t3) : Couple<>

		// ... код недописан ...

};



int main()
{
	Truck truck(18, 300, "Furniture", 5000);
	truck.LoadMore(2500);
	truck.AccellerateBy(100);
	truck.Display();

	Trio<string> t{ "Banana", "Apple", "Orange" };
	cout << "Trio:" << t << endl;
	return 0;
}

// Создайте класс Квадрат, содержащий верхний левый угол и сторону
// Создайте класс Круг, содержащий центр и радиус
// Создайте класс Круг, вписанный в квадрат, унаследованный от классов выше
// 


class Point
{
	int x;
	int y;
public:
	Point() : x{ 0 }, y{ 0 }{}
	Point(int xp, int yp) :x{ xp }, y{ yp }{};
	void SetPoint(int xp, int yp)
	{
		x = xp; y = yp;
	}
	friend ostream& operator<< (ostream& out, Point p)
	{
		out << "(" << p.x << " " << p.y << ")";
		return out;
	}
};

class Square
{
protected:
	int sideLength;
	//агрегация
	Point* corner;
public:
	Square() : sideLength{ 0 }, corner{ nullptr }{}
	
	//void CreateSquare(int angles, int r = 255, int g = 255, int b = 255)
	//{
	//	angles_count = angles;
	//	delete[] color;
	//	color = new int[] {r, g, b};
	//	corner = new Point[angles_count];
	//	if (!corner) exit(0);

	//	int tempX, tempY;
	//	for (int i = 0; i < angles_count; i++)
	//	{
	//		cout << "Enter X Y:" << endl;
	//		cin >> tempX >> tempY;
	//		corner[i].SetPoint(tempX, tempY);
	//	}
	//}


};

class Circle
{
protected:
	int radius;
	//агрегация
	Point* centr;

public:
	Circle() : radius{ 0 }, centr{ nullptr }{}


};

class CircleSquare: Square, Circle