// „исто виртуальна€ функци€

#include <iostream>
using namespace std;

class A // абстрактный класс (предназначен только дл€ наследовани€ дочерним классом)
{
public:
	virtual void v_function1() = 0; // = 0 дл€ того чтобы указать что описывает функцию чистого спецификатора, т.е эту функцию нельз€ вызвать экземпл€ром

};

class B : public A 
{
public:
	virtual void v_function1();


};

void B::v_function1()
{
	cout << "This is B!" << endl;
}

int main2()
{
	//A objA;
	B b;
	b.v_function1();

	//A a.v_function(); //не получитс€ создать у чисто виртуальной функции она служит основой дл€ замены ее у нааследника
	
	return 0;
}

