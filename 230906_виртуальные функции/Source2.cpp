// ������
#include <iostream>
using namespace std;

class Animal // ����������� �����, �.�. ���� ����� ����������� �������
{
public:
	string Name;
	Animal(string nameP) :Name{ nameP } {};
	virtual void Speak() = 0;//��������� �������������� ���� ������� � �������� �������, �.� int Speak ������ ������
};

class Frog :public Animal
{
public:
	Frog(string nameP) : Animal{ nameP } {};
	virtual void Speak();
};

void Frog::Speak()
{
	cout << Name << "say kva-kva" << endl;
}

class Dog :public Animal
{
public:
	Dog(string nameP) : Animal{ nameP } {};

	virtual void Speak();
};
void Dog::Speak()
{
	cout << Name << "say gav-gav" << endl;
}

class Cat :public Animal
{
public:
	Cat(string nameP) : Animal{ nameP } {};

	virtual void Speak();
};

void Cat::Speak()
{
	cout << Name << "say myau- myau" << endl;
}

class Lion : public Cat
{
public:
	Lion(string nameP) : Cat{ nameP } {};
	//virtual void Speak();
	//virtual int Speak(); //��� ������ ������, �� �������� ����
	virtual void Speak(int); // ��� �������������� �����, �.�. ��� ��� �������� ������!, ���������� ����������� �� ����� ����
};
void Lion::Speak(int count=3)
{
	//cout << Name << "say roar-roar" << endl;
	cout << Name << "say " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "roar -";
		cout << "\b\"\n";
	}


}

int main3()
{
	Animal* animals[4] = {
		new Frog("Toad "),
		new Cat("Mittens "),
		new Dog("Spot "),
		new Lion("Simba ")
	};

	for (int i = 0; i < 4; i++)
		animals[i]->Speak();


	Lion l{ "Scar " };
	l.Speak(1);
	
	
	return 0;

}
