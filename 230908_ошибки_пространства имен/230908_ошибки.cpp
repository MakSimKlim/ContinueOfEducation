// 230908_ошибки
// 
// Обработка исключений - исключительная ситуация из стандартов в момент обнаружения ошибки
// 

// try - попробовать. Определяет область кода в которой может возникнуть исключение
// throw - бросать. Оператор, который генерирует исключения и выводит программу из критического блока
// catch - ловить. Оператор, который анализирует сгенерированную ошибку из области, обозначенной словом try
//
// 1) В одном блоке try может быть несколько throw
// 2) Когда срабатывает throw  то выражение в нем формирует в памятти объект,
// тип которого совпадает с типом выражения.
// После чего управление передается за пределы блока try
// Компилятор находит catch с подходящим типом данных и передает упраление ему.
// 3) Может быть несколько catch но их количество не зависит от количества throw
// 4) Двух catch которые принимают один и тот же тип данных существовать не может
//

#include <iostream>

using namespace std;

void syntax()
{
	// общий синтаксис
	try
	{
		// блок кода
		throw 100; // выражение, например, число 
	}
	catch (int g)
	{
		cout << "Error " << g << endl;
	}
}

void division()
{
	try
	{
		float a, b;
		cout << "Enter a and b" << endl;
		cin >> a >> b;
		if (b == 0)
		{
			throw b;
		}
		cout << a << "/" << b << " = " << a / b << endl;
	}
	catch (float g)
	{
		cout << "Error: Cannot divide by " << g << endl;
	}


}

void memory()
{
	try
	{
		const int minSize = 1;
		const int maxSize = 1000;

		int* ptr;
		int size;

		cout << "Enter size: ";
		cin >> size;
		if (size < minSize || size > maxSize)
			throw "Size Error";
		ptr = new int[size];
		if (!ptr) // !ptr (по поведению ptr это nullptr. Пропущен через ! чтобы дать значение true)
			throw "Memory Error";
		int a;
		cout << "Enter digit: ";
		cin >> a;
		if (a == 0)
			throw a;

	}

	catch (int s)
	{
		cout << "Invalid a = " << s << endl;

	}
	catch (const char* a)
	{
		cout << a << endl;
	}

}

void Some()
{
	try
	{
		throw '\n';
	}

	catch (int b)
	{
		cout << b;
	}
	//универсальный catch
	catch (...)
	{
		cout << "Error";
	}

}

void Primer_division()
{
	cout << "Before" << endl;
	division();
	cout << "After" << endl;
}

void test(int t)
{
	cout << "Inside" << endl;
	if (t==2)
	{
		throw "Error: t = 2";
	}
	else if (t == 3)
	{
		throw "Error: t = 3";
	}

}

void infunc()
{
	cout << "Before" << endl;

	try {
		test(4);
		test(2);
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << "After" << endl;


}

void FirstCatch()
{
	try
	{
		throw "In First Catch";
	}
	catch (const char* s)
	{
		cout << "Error " << s << endl;
		throw;//throw без параметров ловит одно и тоже исключение несколько раз
	}
}



int main()
{
	try
	{
		FirstCatch();
	}
	catch (const char* s)
	{
		cout << "Main: " << s << endl;
	}
	return 0;
}

