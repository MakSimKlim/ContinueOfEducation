// создайте абстрактный базовый класс Employee
// У него должна быть быть чисто виртуальная функция Print()
// Создайте три производных класса:
// Manager, Designer, Programmer
// Переопределите Print() для вывода соответствующей должности информации

#include <iostream>
using namespace std;

class Employee
{
public:
	virtual void Print() = 0;
};

class Manager : public Employee
{
public:
	virtual void Print();
};
void Manager::Print()
{
	cout << "This is Manager!" << endl;
}

class Designer : public Employee
{
public:
	virtual void Print();
};
void Designer::Print()
{
	cout << "This is Designer!" << endl;
}

class Programmer : public Employee
{
public:
	virtual void Print();
};
void Programmer::Print()
{
	cout << "This is Programmer!" << endl;
}

int main()
{
	//Employee* employes[3];

	//for (int i = 0; i < 3; i++)
	//	employes[i]->Print();

	Manager manager;
	manager.Print();

	Designer designer;
	designer.Print();

	Programmer programmer;
	programmer.Print();


	return 0;
}

