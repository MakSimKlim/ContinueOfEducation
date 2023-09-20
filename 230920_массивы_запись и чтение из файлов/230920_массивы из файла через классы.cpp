// 230920_массивы из файла через классы
//

#include <iostream>
#include <fstream>
using namespace std;

int Menu()
{
	cout << "\n1. Add new object to file\n";
	cout << "2. Show all objects in file\n";
	cout << "3. Exit\n";
	cout << "> ";
	int choice;
	cin >> choice;
	return choice;
}


class Person
{
	int age;
	string name;
	string surname;
public:
	Person(string, string, int);
	Person();
	~Person();

	void Put();
	void Show();
	void SaveToFile();
	static void DisplayFromFile();//статик - то что доступно всему классу

};

Person::Person()
{
	name = "";
	surname = "";
	age = 0;
}

Person::Person(string nameP, string surnameP, int ageP):
	name{ nameP }, surname{ surnameP }, age{ageP}
{}

Person::~Person()
{}

void Person::Put()
{
	cout << "\nEnter name: ";
	cin >> name;
	cout << "\nEnter surname: ";
	cin >> surname;
	cout << "\nEnter age: ";
	cin >> age;
}

void Person::Show()
{
	cout << name << " " << surname << ", aged " << age << " years.\n";
}

void Person::SaveToFile()
{
	int size;
	fstream f("people.txt", ios::out | ios::binary || ios::app);
	if (!f)
	{
		cout << "Couldn t open file.";
		exit(1);
	}
	// char - потому что единственный, равный 1 байт
	// записываем символы, а потом формируем новый string из этих символов
	f.write((char*)&age, sizeof(age));// (char*)&age - конвертация в указатель на байт с которого начинается age и потом говорим сколько считать байт sizeof(age)
	
	size = name.length();
	f.write((char*)&size, sizeof(size));
	f.write(name.c_str(), size * sizeof(char));

	size = surname.length();
	f.write((char*)&size, sizeof(size));
	f.write(surname.c_str(), size * sizeof(char));

	f.close();
}
void Person::DisplayFromFile()
{
	fstream f("people.txt", ios::in | ios::binary);
	if (!f)
	{
		cout << "Couldn t open the file";
		exit(1);
	}

	char* n, * s;
	int a, temp;

	while (f.read((char*)&a, sizeof(int)))
	{
		f.read((char*)&temp, sizeof(int));
		n = new char[temp + 1];
		f.read((char*)n, temp * sizeof(char));
		n[temp] = '\0'; // чтобы строка выводилась корректно, добавляется символ конца строки

		f.read((char*)&temp, sizeof(int));
		s = new char[temp + 1];
		f.read((char*)s, temp * sizeof(char));
		s[temp] = '\0'; // чтобы строка выводилась корректно, добавляется символ конца строки

		Person person{ n, s, a };//считываем данные с помощью которых создаем новые объекты
		person.Show();
	}
}

int main()
{
	int answer;
	do
	{
		answer = Menu();
		if (answer == 1)
		{
			Person person;
			person.Put();
			person.SaveToFile();
		}
		else
		{
			Person::DisplayFromFile();
		}
		
	} while (answer != 3);

	return 0;
};

