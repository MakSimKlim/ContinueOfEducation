// ����� ����������� �������

#include <iostream>
using namespace std;

class A // ����������� ����� (������������ ������ ��� ������������ �������� �������)
{
public:
	virtual void v_function1() = 0; // = 0 ��� ���� ����� ������� ��� ��������� ������� ������� �������������, �.� ��� ������� ������ ������� �����������

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

	//A a.v_function(); //�� ��������� ������� � ����� ����������� ������� ��� ������ ������� ��� ������ �� � �����������
	
	return 0;
}

