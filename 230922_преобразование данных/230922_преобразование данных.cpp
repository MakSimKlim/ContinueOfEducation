// 230922_преобразование данных
//
// дополнительные операторы приведения типа:
// - const_cast - для снятия свойства постоянстыва
// - volatile - обратная константе (говорит компилятору, что значение будет меняться по какому-то условию)
// - полиморфизм - неявный тип
// - dynamic_cast (можем скастовать дочерний класс в родительский, но не наоборот) - чтобы без ошибок приводить дочерние к лассы к указателю на родительский
// - static_cast - свой способ преобразования для с++
// - reinterpret_cast - переводит один тип в другой (например указателей несовместимых по своей природе)

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

class B: public A // если отсутствует public - блокируется полиморфизм
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
		cout << "Good work A - " << endl;
		ptr_a->Test();

	}
	else
	{
		cout << "Cast error" << endl;

	}


	ptr_b = dynamic_cast<B*>(&obj_a);// если cast не удался, там будет 0
	if (ptr_b)
	{
		cout << "Good work B - " << endl;
		ptr_b->Test();

	}
	else
	{
		cout << "Cast error" << endl;

	}

	ptr_b = dynamic_cast<B*>(&obj_b);// если cast не удался, там будет 0
	if (ptr_b)
	{
		cout << "Good work B - " << endl;
		ptr_b->Test();

	}
	else
	{
		cout << "Cast error" << endl;

	}


	ptr_a = dynamic_cast<A*>(&obj_b);// если cast не удался, там будет 0
	if (ptr_a)
	{
		cout << "Good work B - " << endl;
		ptr_a->Test();

	}
	else
	{
		cout << "Cast error" << endl;

	}

	// свой ститль преобразования данных в С++

	int z = (float)5.56;
	int y = static_cast<int>(7.89); // вот он! - такая запись более грамотна для записи на с++
	cout << z << " " << y;

	// reinterpret_cast - преобразование в другой тип для с++
	int m;
	char* s = const_cast<char*>("This is c-string!");
	cout << s << endl;
	m = reinterpret_cast<int>(s);
	cout << m << endl;


   
}
