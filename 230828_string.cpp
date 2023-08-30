// 230828_string
//
// Кодировки
//
// ASCII - американский стандартный код (7бит)
//
// UNICODE - не кодировка, это таблица символов (11 114 112 позиций, разбиты на 17 блоков, 65000 в каждом блоке)
// 0 блок - основной и содержит символы всех современных алфавитов
// остальные заполнены буквами вымерших языков, различными символами (карточные масти, стрелочки, эмодзи)
// 
// UTF: UTF8, UTF16, UTF32
// 
// первые 127 символов UTF8  занимают 1 байт и совпадают с символами ASCII, поэтому не требуют конвертации
// символы больше 128 занимают от 2 до 6 байт
//
//
//


#include <iostream>
#include <string>

using namespace std;

//void base_stuff()
//{
//	char c{ 'a' }; // - обычный 8 бит char
//	unsigned char c2{ 'a' };
//	//char8_t c8{ u8'a' }; // начиная с версии С++20, UTF8
//	char16_t c16{ u'a' }; // UTF16
//	char32_t c32{ U'a' }; // UTF32 
//	wchar_t chw{ L'a' }; // нестандартный тип Microsoft - определяется реализацией компилятора, UTF16
//
//	//string - char
//	//wstring - wchar_t
//	//u16string - char16_t
//	//u32string - char32_t
//	//typedef basic_string<char> string
//
//	// механика массивов (в С - это единственный способ определения строки).
//	// "-" нет напрямую операций сравнения, присвоения,
//	// невозможность изменения размеров массива, можно только уничтожить
//	// старый и завести новый
//	char text[20]{ "This is C-string" };  // - статичексий способ
//
//	char* text2 = new char[20];           // - динамический способ
//	memcpy_s("This is C-string", 20, text2, 20);
//
//
//	// класс String
//
//	string text{ "This is C++ string" }; // до С++17 необходимо подключать библиотеку string
//	// начиная с версии 17 в ее заголовочном файле уже есть string? поэтому подключать в iosteam string не нужно
//
//}

int main()
{
	//int num;
	//string text; // инициализируется пустой строкой
	//cout << num << "(" << text << ")" << endl;

	// варианты инициализации
	string t1{ "Hello" };
	cout << t1 << endl;

	string t2 = "World";
	cout << t2 << endl;

	string t3(10, 'a');//через () обращение напрямую к конструктору
	cout << t3 << endl;

		char cString[]{ 'a', 'b', 'c', '\0', 'd', 'e', 'f' };
	string cppString{ 'a', 'b', 'c', '\0', 'd', 'e', 'f' }; // символ конца строки будет пропущен и не виден на выводе, но строка знает про него
	cout << cString << endl;
	cout << cppString << endl;

	// подсчет размера и кол-во символов строки
	cout << cppString.length() << endl;
	cout << cppString.size() << endl;
	cout << sizeof(cppString) << endl;

	// замена символа строки
	cppString[3] = '|'; // 3 - индекс 
	cout << cppString << endl;

	//вывод символов по вертикали
	for (auto c : cppString)
	{
		cout << c << endl;
	}

	// поток ввода/ вывода
	//string userInput;
	//cin >> userInput;
	//cout << userInput << endl; // в этом случаепосле пробела символы не выводятся (он завершает ввод т.к. считает пробел завершением ввода)
	// чтобы не было проблемы с пробелом? используем getline:
	//getline(cin, userInput/*, '\n'*/);
	//cout << userInput << endl;

	// инициализация c-строкой 
	string newText{ cString }; // можно инициализировать любым массивом символов
	cout << newText << endl;

	// сравнение строк (лексиграфическое сравнение)
	string s1 = "abc";
	string s2{ 'x', 'y', 'z' };
	string s3{ s1 };
	s3 = s1;
	cout << s1 << " " << s2 << " " << s3 << endl;
	cout << (s1 == s2) << " " << (s2 == s3) << " " << (s3 == s1) << endl;
	cout << (s1 >= s2) << " " << (s1 < s2) << " " << (s3 != s1) << endl;
	
	// конконтинация (сложение) строк, варианты
	cout << s1 + s2 << endl;
	s3 += "cba";
	
	// операция индексирования (изменять и выводить отдельные символы)
	s2[0] = 'v';
	cout << s2[0] << endl;
	cout << s1 << " " << s2 << " " << s3 << endl;

	// методы string ======================================================================
	// 1) методы доступа к элементам
	string test{ "abcdefgh" };
	//cout << test[9] << endl;// при выходе за пределы памяти непредсказуемое поведение программы, крашится программа сообщением Debuger
	//cout << test.at(9) << endl;// at дает исключение при выходе за пределы памяти, более штатная вещь, которую можно обработать способом ниже:
	//test.at(3) = 'a'; // изменение символа
	//cout << test << endl;
	// 
	//ещё методы доступа к элементам
	cout << test.front() << endl;// возвращает ссылку на первый символ (поэтому их можно поменять)
	test.front() = '1';//поэтому их можно поменять
	cout << test.back() << endl;// возвращает ссылку на последний символ (поэтому их можно поменять)
	test.data(); // возвращает строчку как С-строчку
	const char* cTest = test.data(); //но эта строчка будет константной и ее нельзя изменить

	// 2) методы итераторы (возвращают указатели на определенные элементы строчки)
	test.begin(); // на первый элемент
	test.end(); // на последний элемент
	test.rbegin(); // реверсивный итератор, перебирает строку в обратном порядке
	test.rend();// реверсивный итератор, перебирает строку в обратном порядке

	// перебор с первого до последнего символа
	for (auto it = test.begin(); it < test.end(); it++) 
	{
		cout << *it << " "; // разыменование указателя 
	}
	cout << endl;

	// перебор с последнего до первого символа
	for (auto it = test.rbegin(); it < test.rend(); it++)
	{
		cout << *it << " ";// разыменование указателя 
	}
	cout << endl;

	//test.cbegin();// возвращают константные указатели, запрещающие изменения
	//test.crbegin();// возвращают константные указатели, запрещающие изменения

	// 3) методы поиска
	string search{ "banana" };
	int index = search.find("na"/*4, 2*/);// 4 - с какого символа искать, 2- сколько символов сравнивать
	if (index != string::npos)
	{
		cout << index << endl;
	}
	index = search.rfind("na");// 4 - с какого символа искать, 2- сколько символов сравнивать
	if (index != string::npos)
	{
		cout << index << endl;
	}
	// находит символ равный одному из последовательностей символов (первым, последним)
	cout << search.find_first_of("an") << endl;
	cout << search.find_first_not_of("an") << endl;
	cout << search.find_last_of("an") << endl;
	cout << search.find_last_not_of("an") << endl;

	// 4) методы редактирования (для изменения строк): assign, clear, erase, insert
	string edit{ "This is a C++ string" };
	string str{ "ext string" };
	cout << edit.assign(str, 3, 7) << endl; // 3, 7 - подстрока с 3-го по 7-й символ
	cout << edit.assign(str, 3) << endl; // 3 - подстрока с 3-го до последнего символа
	cout << edit.assign(5, 'a') << endl; // передается в подстроку (вырезание подстрок)
	cout << edit.assign("Hello World") << endl;
	
	edit.clear();// clear очищает строку
	cout << edit;
	edit = "This is a C++ string";
	
	edit.erase(3, 6);// erase удаляет часть строки (3 - начальная позиция и 6 - сколько символов удалить)
	cout << edit;
	edit.erase(edit.end() - 3);// с использованием итератора указывается с какой по какую по
	cout << edit;
	edit.erase(edit.begin() + 2, edit.end() -2 );// с использованием итератора
	cout << edit;
	edit.erase(edit.begin());
    cout << edit;

	edit.insert(1, "icki");// вставляет строчку
	cout << edit;
	edit.insert(1, "hickid", 1, 4);// 1- с какой поз, 4- кол-во символов
	cout << edit;
	edit.insert(4, 5, 'a'); // в 4 позицию втавит 5 букв А
	cout << edit;
	edit.insert(edit.begin() + 1, 'c');// передать в качестве аргумента итератор (edit.begin() + 1 - следующая буква за началом)

	edit.push_back('F');// push_back - добавляет в конец cимволы, pop_back - удаляет последний символ
	cout << edit;
	edit.pop_back();
	cout << edit;

	edit.append("EndOfLine"); // добавляет строчку, аналогично insert но не указываем куда вставлять, т.к. он автоматом добавляет в конец строки
	edit.append("EndOfLine", 2, 4);
	edit.append(5, 'a');
	cout << edit;

	edit.replace(2, 3, "str"); // замена (на что заменяем)
	edit.replace(edit.begin() + 5, edit.end() - 2, "str");
	edit.replace(edit.begin() + 5, edit.end() - 2, 3, 'b');
	cout << edit;

	cout << edit.substr(5, 3) << endl; // с какой позиции какую подстроку возвращает, но оригинальную строку не изменяет 
	cout << edit << endl;

	char cp[10]{0};// метод копирования в с-строки (cp - указатель, 8 - позиция с которой копируем, 10 - количество)
	edit.copy(cp, 8, 10);
	cout << cp << endl;

	edit.resize(20, '#');//20- число до которого изменяем размер строки, что не влезло, то оно теряется
	edit.resize(3); // по умолчанию пустое пространство заполняется символами окончания строки
	cout << edit << endl;

	string edit2{ "This is a non-edited string" };
	edit.swap(edit2); // меняет местами строки
	cout << edit << " " << edit2 << endl;

	// 5) методы вместимости строки 
	string capacity;//(память выделяется с небольшим запасом)
	cout << capacity.empty() << endl;// проверяет является ли строчка пустой (по умолчанию - пустая)
	cout << capacity.size() << endl; // сколько на самом деле символов
	cout << capacity.length() << endl;// сколько на самом деле символов
	cout << capacity.max_size() << endl;// сколько максимально символов может быть в строке
	cout << capacity.capacity() << endl;// сколько дефакто выделенов памяти сейчас под строчку
	capacity.reserve(20);// выделение и увеличение количества памяти для 20 символов
	capacity.reserve(10);// выделение и уменьшение количества памяти для 10 символов
	cout << capacity.capacity() << endl;// сколько дефакто выделенов памяти сейчас под строчку
	capacity.shrink_to_fit();// автоматическое выделение памяти

	// 6) сервисные функции методы
	string friends;
	getline(cin, friends, '\n'); // метод переноса строки
	cout << friends << endl;

	stoi(friends);// преобразует число встроку int 
	stol(friends);// преобразует число встроку long 
	stoll(friends);// преобразует число встроку long long



	return 0;

}

