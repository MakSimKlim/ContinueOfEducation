// ����������� �����������
// ����������� ������������� �� ����� ���� � ������� �� ������������


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

class Something // ��� ����������� ����� � ����������� ������������
{
public:
	virtual ~Something() = 0;
};
Something::~Something() {}; // �����������! ����� �� ���� ������, ����� ���������� ������������ ����������� ������������ ������

class SomethingElse : Something // ���������
{
public:
	virtual ~SomethingElse();
};



int main()
{
	Array* ar;
	ar = new DoubleArray{ 5,6 };
	delete ar; // ����������� ������ Array, �.�. ���������� �� ����� ��� DoubleArray �� �� ������� ����������
	// ����� ���������� ��� � Array � DoubleArray
	// ����� ����������� ������� ��� ������������
	SomethingElse* se = new SomethingElse();
	delete se;//��������� ������ ��-�� ������ ����������� �� ����� ������������ ������, ���� �� ������� ���������� ������������ �����������

	return 0;
}