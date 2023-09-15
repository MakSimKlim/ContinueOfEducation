// 230915_ функции для работы с файлами

#define _CRT_SECURE_NO_WARNINGS 0; // чтобы не было ошибки на fopen
#include <iostream>
#include <stdio.h>


// rename(char* oldname, char* newname);
// возвращает 0, если имя файла было изменено,
// и ненулевое значение, если произошла ошибка.
// NB! Если указать полное имя, и если путь к файлу
// в newname будет другим, файл будет не только переименован,
// но и перенесен
// 
// remove(const char* filename)
// удаляет указанный файл (минуя корзину - безвозвратно).
// Возвращает 0, если файл был удален, и ненулевое значение,
// если его удаолить не удалось
// NB! В момент удаления, файл должен быть закрыт. 
// Помните, что такое удаление необратимо

#include <io.h>
//_findfirst(char* path, _findata_t * fileinfo);
//Находит файлы по указанному пути с использованием маски.
//path - комбинация пути и маски. Маска - это строка, содержащая символы
// *(любая последовательность символов) и ? (единичный символ)
// Например маска для поиска всех файлов pdf  в папке D:\\Kazin
// будет выглядеть. как D:\\Kazin\*.pdf
// будет выглядеть. как D:\\Kazin\*.??
// fileinfo - указатель на объект спец.структуры
// Структура содержит следующие поля:
// unsigned attrib - атрибуты файла
// _A_NORMAL - обычный файл без запретов на чтение или запись
// _A_RDONLY - файл открыт только для чтения
// _A_HIDDEN - файл скрыт
// _A_SYSTEM - файл является системный
// _A_SUBDIR - папка
// _A_ARCH - архив
// time_t time_access время/дата последнего открытия
// time_t time_write время/дата последнего редактирования
// _fsize_t size - размер файла
// char name[260] - имя файла
//
// Функция возвращает уникальный номер, который соответствует
// списку файлов, хранящемуся в оперативной памяти. У него тоже есть
// указатель на текущий файл

// _filenext(long done, _findata_t* fileinfo);
// done - это уникальный номер, который вернула _findfirst
// fileinfo - указатель на объект структуры с информацитей о файле
// вернёт -1, когдадостигнут конец списка файлов
// 
// _findclose(long done);
// Очищает память от списка файлов
// 

#include <string.h>
using namespace std;

void findfiles()
{
	string path, mask;
	cout << "Enter path to directory: ";
	cin >> path;
	cout << "Enter mask for files: ";
	cin >> mask;
	path += mask;
	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(path.c_str(), fileinfo);
	if (done != -1)
	{
		cout << fileinfo->name << endl;
		while (done > 0)
		{
			done = _findnext(done, fileinfo);
			cout << fileinfo->name << endl;

		}
	}
	_findclose(done);

}

void removal()
{
	//удаление
	string path;
	cout << "Enter file to delete: ";
	cin >> path;

	remove(path.c_str());
}

void renamefile()
{
	// перемещение и переименование
	string oldpath, newpath;
	cout << "Enter old file name: ";
	cin >> oldpath;

	cout << "Enter new file name: ";
	cin >> newpath;

	rename(oldpath.c_str(), newpath.c_str());



}

int main()
{
	return 0;
};