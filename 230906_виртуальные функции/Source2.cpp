// пример
#include <iostream>
using namespace std;

class Animal // абстрактный класс, т.к. есть чисто виртуальная функция
{
public:
	string Name;
	Animal(string nameP) :Name{ nameP } {};
	virtual void Speak() = 0;//запрещено переопределние этой функции в дочерних классах, т.е int Speak выдаст ошибку
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
	//virtual int Speak(); //так писать нельзя, см комменты выше
	virtual void Speak(int); // так переопределять можно, т.к. это уже параметр другой!, произойдет отступление на класс выше
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
