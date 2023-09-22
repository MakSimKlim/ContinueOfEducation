// 230922_преобразование данных
//
// дополнительные операторы приведения типа:
// - const_cast - для снятия свойства постоянстыва
// - volatile - обратная константе (говорит компилятору, что значение будет меняться по какому-то условию)
// - полиморфизм - неявный тип
// - dynamic_cast

#include <iostream>
using namespace std;

void test_pow(const int* v)
{
	int* temp;
	// снимается постоянство
	temp = const_cast<int*>(v);
	*temp = *v * *v;

}

volatile int v;

class A
{
public:
	virtual void Test() { cout << "I'm A!\n"; }


};

class B:A
{
public:
	void Test() { cout << "I'm B!\n"; }

};

void TestClass(A c)
{
	c.Test();
}


float sqr(float b)
{
	return b * b;
}

int main()
{
	// неявное преобразование
	int a = 5.45;
	cout << sqr(a) << endl;

	// явное преобразование (оператор приведения к типу)
	float b = (int)5.45;
	float c = (float)24 / a;
	cout << b << endl;
	cout << c << endl;

	// преобразование с помощью const_cast
	int x = 10;
	cout << x << endl;
	test_pow(&x);
	cout << x << endl;

	// преобразование классов
	A* ptr_a, obj_a;
	B* ptr_b, obj_b;

	ptr_a = dynamic_cast<A*>(&obj_a);// если cast не удался, там будет 0
	if (ptr_a)
	{
		cout << "Good work A - ";
		ptr_a->Test();

	}
	ptr_b = dynamic_cast<B*>(&obj_a);// если cast не удался, там будет 0
	if (ptr_b)
	{
		cout << "Good work B - ";
		ptr_b->Test();

	}




   
}
