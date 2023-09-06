// виртуальные деструкторы
// виртуальных конструкторов не может быть в отличие от деструкторов


#include <iostream>
using namespace std;

class Array
{
private:
	int* data;
	int size;
public:
	Array(int sizeP) :size{ sizeP }, data{ new int[size] }
	{}

	//~Array()
	//{
	//	cout << "Array destriyed" << endl;
	//	delete[] data;
	//}
	virtual	~Array()
	{
		cout << "Array destriyed" << endl;
		delete[] data;
	}

};
class DoubleArray: public Array
{
private:
	int* data2;
	int size2;
public:
	DoubleArray(int size1P, int size2P) :Array{ size1P }, size2{size2P}
	{}

	//~DoubleArray()
	//{
	//	cout << "DoubleArray destriyed" << endl;
	//	delete[] data2;
	//}
	virtual	~DoubleArray()
	{
		cout << "DoubleArray destroyed" << endl;
		delete[] data2;
	}


};

class Something // это абстрактный класс с виртуальным деструктором
{
public:
	virtual ~Something() = 0;
};
Something::~Something() {}; // обязательно! чтобы не было ошибки, нужна реализация виртуального деструктора абстрактного класса

class SomethingElse : Something // наследник
{
public:
	virtual ~SomethingElse();
};



int main()
{
	Array* ar;
	ar = new DoubleArray{ 5,6 };
	delete ar; // уничтожится только Array, т.к. компилятор не знает про DoubleArray из за раннего связывания
	// чтобы уничтожить все и Array и DoubleArray
	// нужно деструкторы сделать оба виртуальными
	SomethingElse* se = new SomethingElse();
	delete se;//возникает ошибка из-за вызова деструктора из чисто виртуального метода, если не сделать реализацию виртуального деструктора

	return 0;
}