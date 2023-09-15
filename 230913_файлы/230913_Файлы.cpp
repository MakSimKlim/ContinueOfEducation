﻿// 230913_Файлы
#define _CRT_SECURE_NO_WARNINGS 0; // чтобы не было ошибки на fopen

#include <iostream>

#include <stdio.h>
// STDIO
// FILE *fopen(const char *filename, const char *mode)
// filename - путь к файлу
// mode - тип доступа
// Типы доступа для текстовых файлов
// r -чтение, ошибка если файла нет
// w - запись с начала, если файла нет, создается, если есть, перезаписывается 
// a - запись в конец, если файла нет, создается
// r+ -чтение и запись (файл должен существовать)
// w+ - чтение и запись (как w) 
// a+ - добавление и чтение (как а)
// Для двоичных файлов, перед типом доступа надо посттавить b
// Например br для чтения с ошибкой при отсутствии файла
//
// Если fopen отработало успешно, возвращает указатель на файл (FILE*)
// Если была ошибка, возвращает ноль
// 
// int fclose(FILE* stream)
// функция закрывает файл
// stream - указатель на закрываемый файл
// Функция возвращает 0, если прошла успешно, или EOF в случае ошибки
// 
// EOF - это маркер конца файла
// 
// char *fgets(char *str, int n, FILE* stream)
// Считывает строку, начиная с текущей позиции.
// Считывание останавливается, когда:
//  - встречен символ перехода на новую строку (\n) (он тоже считывается)
//  - достигнут конец файла
//  - считано n-1 символов
// Когда считывание остановлено, строка помещается в str
// n - это количество str
// Если всё прошло успешно, возвращается считанная строка
// Если была ошибка или достигнут конец файла, возвращается 0
// 
// int fputs(const char *str, FILE *stream)
// Записывает строчку в файл, начиная с текущей позиции
// str -строка для записи
// stream - указатель на файл, куда происходит запись
// Если всё прошло успешно, возвращается неотрицательное число
// Иначе возвращает EOF\
// 
// size_t fread(void *buffer, size_t size, size_t count, FILE *stream)
// Считывает данные из файла в буфер
// buffer - адрес массива для записи данных
// size - размер элемента массива в байтах
// count - максимальное количество элементов для считывания
// stream- указатель на открытый файл
// Возвращает количество считанных байт
// 
// size_t fwrite(const void* buffer, size_t size, size_t count, FILE *stream)
// Функция записывает массив данных в файл
// buffer - адрес записываемого массива
// size - размер элемента массива в байтах
// count - максимальное количество элементов для считывания
// stream- указатель на открытый файл
// Возвращает количество записанных байт
// 
// int feof(FILE *stream)
// Проверяет достиг ли файловый указатель конца файла
// Возвращает ненулевое значение, если конец файла достигнут, иначе 0
// 
// int _fileno(FILE *stream)
// возвращает дескриптор файла
// 
// int fseek(FILE *stream, int offset[, int whence])
// Устанавливает смещение файлового указателя в файле
// stream - указатель на открытый файл
// offset - количество байт, на которое нужно сместиться
// whence - точка, от которой производится смещение
// SEEK_SET 0 - начало файла
// SEEK_CUT 1 - текущая позиция файлового указателя
// SEEK_END 2 - конец файла
// Возвращает 0, если указатель был перемещен, и ненулевое значение,
// если была ошибка при перемещении.
//

#include <io.h>
// IO
// int _access(const char* path, int mode)
// определяет доступ к файлу или папке
// path - это путь к файлу или папке
// mode- это флаги дл\я проверки
// 00 - проверка на существование
// 02 - проверка на разрешение на запись
// 04 - проверка на разрешение на чтение
// 06 - проверка на чтение и запись
// Если разрешнеи есть возвращает 0, иначе -1
// 
// long _filelength(int handle)
// handle - дескриптор файла
// в случае ошибки возвращает -1
// 
// int _locking(int handle, int mode, long nbytes)
// Блокирует или разблокирует байты файла, начиная с позиции файлового указателя
// handle - дескриптор файла 
// nbytes - количество байт для блокировки
// mode - 
// _LK_LOCK - блокирует байты, если заблокировать не удалось, через 1 секунду повторяет попытку
// Если после 10 попыток не удалось, возвращает -1
// _LK_NBLСK - блокирует байты
// если заблокировать не удалось, возвращает -1
// _LK_RLCK - то же самое что и _LK_LOCK
// _LK_NBRLCK - то же самое что и _LK_NBLСK 
// _LK_UNLCK - разблокирует заблокированные байты
// Возвращает -1 в случае ошибки, если 0 если всё успешно
// Нужно подключать sys/locking.h
//  
//
//

#include <Windows.h>
#include <string.h>
using namespace std;

bool CopyFile(const char* source, const char* dest)
{
	const int size = 65536;
	FILE* src, *dst;

	///открытие файла 
	if (!(src = fopen(source, "rb")))// проверка на ошибки
	{
		return false;
	}
	int src_handle = _fileno(src);

	char* data = new char[size];
	if (!data)
	{
		return false;
	}
	// открыть файл куда будем копировать
	if (!(dst = fopen(dest, "wb")))
	{
		//проверка наошибки
		delete[] data;
		return false;
	}
	int realsize;
	// пока не достигнут конец файла, двигается файловые указатели
	// эта конструкция частов стречается при работе с файлами
	while (!feof(src))
	{
		realsize = fread(data, sizeof(char), size, src);
		fwrite(data, sizeof(char), realsize, dst);
	
	}
	fclose(src);
	fclose(dst);
	delete[] data;
	return true;


}

int main()
{
	string src_path;
	string dst_path;

	setlocale(LC_ALL, "Rus");

	cout << "ВВедите путь к файлу-источнику: ";
	cin >> src_path;

	//проверка существует ли этот файл
	// src_path.c_str() - конвертация в char (метод c_str)
	if (_access(src_path.c_str(), 00) == -1)
	{
		cout << "\nУказан неверный путь к файлу\n";
	}

	cout << " Введите путь к файлу-копии: "; // этот файл необязательно должен существовать
	cin >> dst_path;
	//если файл существкет, провери мего наперезапись
	if (_access(dst_path.c_str(), 00) == 0)
	{
		cout << "Такой файл существует. Перезаписать? Y/N >";
		string answer;
		cin >> answer;
		if (answer.find_first_of("yYдД"))//если хотим перезаписать
		{
			if (_access(dst_path.c_str(), 02) == -1) //проверка права на запись
			{
				cout << "\nНет прав записи файла.\n";
			}
		}
		else {
			cout << "\nОперация отменена!\n";
		
			return 0;
		}

	}

	if (!CopyFile(src_path.c_str(), dst_path.c_str()))
	{


	}


	return 0;
}

