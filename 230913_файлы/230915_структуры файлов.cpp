// 230915_структуры файлов
//
#define _CRT_SECURE_NO_WARNINGS 0; // чтобы не было ошибки на fopen

#include <iostream>
#include <stdio.h>
using namespace std;


struct Person
{
	char* name;
	short age;
};

int main()
{
	// в а положили, из а в файл, из файла в b
	Person a, b;
	string name;


	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> a.age;

	a.name = new char[name.length()+1];
	memcpy_s(a.name, name.length() + 1 * sizeof(char), name.c_str(), name.length() + 1 * sizeof(char));

	FILE* f = fopen("Test.txt", "w+b");
	if (!f) exit(0);

	fwrite(&a, sizeof(Person), 1, f);
	fclose(f);

	f = fopen("Test.txt", "r+b");
	if (!f) exit(0);

	fread(&b, sizeof(Person), 1, f);
	fclose(f);

	cout << "Name: " << b.name << "\nAge: " << b.age << endl;

	return 0;
}

