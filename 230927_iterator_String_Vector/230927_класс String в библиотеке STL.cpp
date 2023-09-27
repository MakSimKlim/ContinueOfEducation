// 230927_класс String в библиотеке STL
//
//

#include <iostream>
#include <string.h> // устаревшая библиотека, нужна, чтобы запускался старый код
// #include <string> // 

using namespace std;

void str_methods()
{
	std::string s = "Hello World";// std строка - std::string
//std::cin >> s;
	std::cout << s << std::endl;
	//std::string s2;
	//s2 = s;
	//s2 != s;
	//s2 > s;
	char c = s[2];
	s[1] = 'A';
	std::cout << c << ' ' << s << std::endl;
	s[5] = '\0';
	std::cout << s << " " << s.c_str() << std::endl;
	std::string oString = "ghi";
	s = "abc";
	s[1] = '\0';
	s.insert(1, oString);
	s.append("def");
	std::cout << s << " " << s.length() << ' ' << s.size() << std::endl;
	//std::cout << s.length() << ' ' << s.size() << std::endl;
	s.erase(4, 3);
	std::cout << s << " " << s.length() << ' ' << s.size() << std::endl;
	s.replace(4, 1, "foobar");
	std::cout << s << " " << s.length() << ' ' << s.size() << std::endl;
	// конструктор по умолчанию определен в string
	std::string emptyString;
	std::cout << s.empty() << " " << emptyString.empty() << std::endl;

	s = "bar bar bar";
	std::cout << s.find("bar") << std::endl; //находит первое вхождение
	std::cout << s.rfind("bar") << std::endl; // находит последнее вхождение
	std::cout << s.find_first_of("b") << std::endl; // находит первый указанный символ
	std::cout << s.find_first_not_of("bar") << std::endl; //находит первый несуществующий символ
	std::cout << s.substr(4, 3) << std::endl; // подстрока


}



int main()
{
	//string s = "Hello World";
	string s = "World";
	int word_end = s.find(' ');
	if (word_end>=0)//если не находит пробел
	{
		string first_word = s.substr(0, word_end); // подстрока до пробела
		cout << s << endl;
		cout << first_word << endl;
	}
	else
	{
		cout << s << endl;
	}
	return 0;


}

