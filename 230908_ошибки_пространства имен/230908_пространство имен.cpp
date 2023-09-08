// 230908_пространство имен
//
// пространство имен
//
// чтобы не использовать оператор :: локальное пространство имен можно слить с глобальным, только если дублирующих имен внутри локальнокго пространства больше нигде не используется
// директива using достает всё из этого пространства
// 

#include <iostream>
using namespace std;

void fire()
{
	cout << "This is global fire function" << endl;
}

namespace Combat
{
	void fire()
	{
		cout << "An arrow was fired" << endl;
	}
}
namespace Combat
{
	void sword()
	{
		cout << "A sword was used" << endl;
	}
}

// если две области видимости с одинаковыми именами, то компилятор сливает их в одну, но новую функцию, например fire(невозможно переопределить)


namespace Exploration
{
	void fire()
	{
		cout << "Torch was lit" << endl;
	}
	void global_fire()
	{
		::fire();
		//fire();
	}
}

namespace Dragons
{
	class Dragon
	{
		int gold;
	public:
		Dragon() :gold{ 50 } {};
		int getGold() { return gold; }

	};
}

// для безымянного пространства уникальное имя присвоится автоматически
namespace
{
	int test{ 5 };
	void func() { cout << "::func" << endl; }
}

int main()
{
	Combat::fire(); // локальное пространство имен Combat
	Combat::sword();

	Exploration::fire();// локальное пространство имен Exploration

	::fire(); // глобальное пространство имен

	Exploration::global_fire();// локальное пространство имен Exploration вызывает глобальное

	// слияние пространств имен
	using Dragons::Dragon;//объявление using
	Dragon d1;
	cout << d1.getGold() << endl;
	Dragon d2;
	cout << d2.getGold() << endl;

	//здесь безымянное пространство имен, по симентике похожие с глобальным func();
	::func();
	cout << ::func << endl;


	return 0;
}
