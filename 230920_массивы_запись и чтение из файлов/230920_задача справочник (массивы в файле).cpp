// 230920_задача справочник (массивы в файле)
// 
// Создать справочник
// Он хранит телефоны
// Каждый телефон имеет:
//  - имя
//  - номер (в виде строчки)
//  - bool Является ли компанией 
//  - Адрес
// Справочник умеет сохранять в файл и доставать из файла телефоны

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

class Guide
{
	int telNumber;
	string name;
	//bool company;
	string adress;
public:
	Guide(string, int, /*bool,*/ string);
	Guide();
	~Guide();

	void Put();
	void Show();
	void SaveToFile();
	static void DisplayFromFile();//статик - то что доступно всему классу

};

Guide::Guide()
{
	name = "";
	telNumber = 0;
	//company = false;
	adress = "";
}
Guide::Guide(string nameP, int telNumberP, /*bool companyP,*/ string adressP) :
	name{ nameP }, telNumber{ telNumberP }, /*company{ companyP }, */ adress{ adressP }
{}

Guide::~Guide()
{}

void Guide::Put()
{
	cout << "\nEnter name: ";
	cin >> name;
	cout << "\nEnter telephone number: ";
	cin >> telNumber;
	/*cout << "\nis it a company: ";
	cin >> company;*/
	cout << "\nEnter adress: ";
	cin >> adress;

}

void Guide::Show()
{
	cout << name << ", tel: " << telNumber /*<<  ", company affiliation: "<< company*/<< ", adress: " << adress << "\n";
}

void Guide::SaveToFile()
{
	int size;
	fstream f("guide.txt", ios::out | ios::binary || ios::app);
	if (!f)
	{
		cout << "Couldn t open file.";
		exit(1);
	}
	// char - потому что единственный, равный 1 байт
	// записываем символы, а потом формируем новый string из этих символов
	f.write((char*)&telNumber, sizeof(telNumber));// (char*)&age - конвертация в указатель на байт с которого начинается age и потом говорим сколько считать байт sizeof(age)

	size = name.length();
	f.write((char*)&size, sizeof(size));
	f.write(name.c_str(), size * sizeof(char));

	size = adress.length();
	f.write((char*)&size, sizeof(size));
	f.write(adress.c_str(), size * sizeof(char));

	f.close();

}
void Guide::DisplayFromFile()
{
	fstream f("guide.txt", ios::in | ios::binary);
	if (!f)
	{
		cout << "Couldn t open the file";
		exit(1);
	}

	char* n, * a;
	int t, temp;
	//bool c;

	while (f.read((char*)&t, sizeof(int)))
	{
		f.read((char*)&temp, sizeof(int));
		n = new char[temp + 1];
		f.read((char*)n, temp * sizeof(char));
		n[temp] = '\0'; // чтобы строка выводилась корректно, добавляется символ конца строки

		f.read((char*)&temp, sizeof(int));
		a = new char[temp + 1];
		f.read((char*)a, temp * sizeof(char));
		a[temp] = '\0'; // чтобы строка выводилась корректно, добавляется символ конца строки

		Guide guide{ n, t, /*c,*/ a};//считываем данные с помощью которых создаем новые объекты
		guide.Show();
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
			Guide guide;
			guide.Put();
			guide.SaveToFile();
		}
		else
		{
			Guide::DisplayFromFile();
		}

	} while (answer != 3);

	return 0;





}

