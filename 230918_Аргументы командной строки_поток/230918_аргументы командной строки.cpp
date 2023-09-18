// 230918_аргументы командной строки
//
#define _CRT_SECURE_NO_WARNINGS 0; 

#include <iostream>

#include<stdio.h>
using namespace std;

int main(int argc, char * argv[])// первый параметр - путь, второй - значение
{
	//FF0ADA - написать это в Проект - Свойства - Отладка- Аргументы команды
	string color = "000000";
	string filehtml = "<html><head></head><body bgcolor = \"#";

	FILE* f = fopen("D:\\index.html","w");
	if (!f) exit(0);

	if (argc >= 2)
	{
		color = argv[1];


	}

	filehtml += color;

	filehtml += "\"></body></html>";

	fputs(filehtml.c_str(), f);
	fclose(f);
	cout << "File created!";

}
