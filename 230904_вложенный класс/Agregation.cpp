// Агрегация
// Агрегироавание - вкл объекта одного класса в состав объекта другого
//
// Композиция - агрегация на нескольких уровнях 



#include <iostream>

using namespace std;

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

class Polygon
{
	int angles_count;
	int* color;
	// агрегация
	Point* corner;
public:
	Polygon()
	{
		color = new int[3]{0,0,0};
		angles_count = 0;
		corner = nullptr;
	}

	void CreatePolygon(int angles, int r = 255, int g = 255, int b = 255)
	{
		angles_count = angles;
		delete[] color;
		color = new int[] {r, g, b};
		corner = new Point[angles_count];
		if (!corner) exit(0);

		int tempX, tempY;
		for (int i = 0; i < angles_count; i++)
		{
			cout << "Enter X Y:"<< endl;
			cin >> tempX >> tempY;
			corner[i].SetPoint(tempX, tempY);
		}
	}

	void ShowPolygon() const
	{
		cout << "Color: #" << hex << color[0]; // hex - ключевое слово вывода чисел в поток в 16 ричной системе
		cout << color[1];
		cout << color[2] << dec << endl; // dec - ключевое слово вывода чисел в поток в десятеричной системе
		for (int i = 0; i < angles_count; i++)
		{
			cout << corner[i] << " ";
		}
		cout << endl;
	}
};

int main()

{
	Polygon P;
	P.CreatePolygon(3, 125, 56, 100);
	P.ShowPolygon();
	return 0;
};
