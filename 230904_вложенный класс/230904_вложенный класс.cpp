// 230904_вложенный класс
// 
// Класс который сущ внутри класса, и является членом своего класса 
// Его можно использ внутри метода и поля этого класса
// 
//

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "This is global A" << endl;
	}
};

class B
{

	string value;

	class A // не имееет доступа к приватным полям В
	{
	public:
		static int amount_of_a;
		int value;
		
		//friend class B; // после этого В имеет доступ к А
	
		//A() : value{ 0 }
		//{
		//	cout << "This is A inside B" << endl;
		//};
		//A(int v) : value{ v } {}
		//
		A();
		A(int v);
		friend A operator+(A p1, A p2)
		{
			return A{ p1.value + p2.value };
		}

		//void refB(B& b1)
		//{
		//	b1.getValue();
		//}
	};

	class C;
	C* c;

	class R;
	class F
	{
		R* r;
	};
	class R
	{
		F* f;
	};


public:
	B()
	{
		value = " ";
		A obj;
	};
	B(string v) : value{ v } {}

	//getValue() - недописана часть кода
	
};

int B::A::amount_of_a{ 0 };

B::A::A()
{
	value = 0;
}

B::A::A(int val) : value{ val } {};

class B::C
{
public:
	char value;
	C() { value = '\0'; }
	C(string s) :  value{ s[0] }  {}
	C(char c) : value{ c } {}
};

int main1()
{
	B b;
	A a;
	//B::A ba;
	return 0;
}

