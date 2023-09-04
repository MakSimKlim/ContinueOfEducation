// \множественное наследованике
//
#include <iostream>

using namespace std;


// синтаксис
class A
{
public:
	A() { cout << "A!"; }
	~A() { cout << "~A!"; }
};

class B
{
	B() { cout << "B!"; }
	~B() { cout << "~B!"; }

};

class AB : public A, public B
{};

int main()
{
	AB ab;
	return 0;
};
