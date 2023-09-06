// виртуальный базовый класс
// вариант когда наследуется два одинаковых ментода

#include <iostream>
using namespace std;

class A
{
public: 
	int val;
};

//class B : public A {};
//class C : public A {};
class B : public virtual A {}; // с virtual наследуется только одна копия А и теперь только один val
class C : public virtual A {};


class D : public B, public C
{
public:
	//int& GetVal()
	//{
	//	return B::val;
	//}
	//int& GetVal2()
	//{
	//	return C::val;
	//}

	int GetVal()
	{
		return val;
	
	}
};

int main4()
{
	D d;
	//d.GetVal() = 5;
	//d.GetVal2() = 6;
	//cout << d.GetVal() << " " << d.GetVal2() << endl;

	cout << d.GetVal() << endl;

	return 0;
}