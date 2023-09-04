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

int main()
{
	Truck truck(18, 300, "Furniture", 5000);
	truck.LoadMore(2500);
	truck.AccellerateBy(100);
	truck.Display();
}