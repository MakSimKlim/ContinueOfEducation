// 230927_ класс Vector
// 
// это динамический массив со счетчиком элементов
//
// Шаблон 
// template<class T, class Allocator = Allocator<T>>
// class vector
// 
// Конструкторы Vector'a:
// 
// explicit vector(const Allocator &a = Allocator()) // явный конструктор, который всегда вызывается явно, создает пустой вектор
// explicit vector(size_t num, const T& val = T(), const Allocator &a = Allocator()). // создает динамический массив с указанным кол-вом эл-тов, и что в них лежит
// vector(const vector<T, Allocator> &ob)//копия другого вектора (конструктор копирования)
// template<class InIter> vector(InIter start, InIter end, const Allocator &a = Allocator())//вектор который содержит всё что указано в диапазоне
//
// Операторы сравнения для векторов:
// operator ==
// operator !=
// operator >
// operator <
// operator >=
// operator <=
//
//Методы vector
// template<class InIter> //помещает в  вектор последовательность, заполняет вектор промежутком от start to end
// void assign (InIter start, Initer end);
//
// void assign(size_t num, const T &val)// заполняет вектор количеством num элементов равнфых val
//
// reference at(size_t i) // возвращает ссылку на элемент по индексу i, в отличие от [] генерирует ошибку при выходе за пределы массива (отлавливает ошибку)
// const reference at(size_t i) const
//
// T& - reference // идентичные записи (reference - ссылка)
// const reference back() const - возвращает ссылку на последний элемент в векторе
// 
// iterator begin()
// const iterator begin() const - возвращает итератор (указатель) для первого элемента в векторе
// 
// size_t capacity() const
// Возвращает емкость вектора. емкость - кол-во эл-тов, которое может хранить вектор до того, как возникает необходимость в выделении дополнительной памяти
// 
// void clear()
// удаляет все элементы из вектора
// 
// bool empty() const
// истина если вектор пуст и ложь если вектор имеет элементы
// 
// const iterator end() const;
// iterator end()
// возвращает итератор для конца вектора 
// 
// reference front()
// const reference front() const
// возвращает ссылку на первый элемент вектора
// 
// iterator erase(iterator i)
// удаляет элемент, на который указывает итератор i
// возвращает итератор, который указывает на следующий после удаленного элемента
// 0 1 2 3 4 5      0 1 2 4 5
//       ^                ^
// 
// перегрузка для erase
// iterator erase(iterator start, iterator end)
// Удаляет элементы, расположенные в диапазоне, заданном параметрами start end
// Возвращает итератор, указывающий на  элемент, расположенный сразщу после удаленного
// 0 1 2 3 4 5 6   0 4 5 6
//   ^   ^           ^
// 
// allocator<T> get_allocator() const
// возвращает распределитель вектора
// 
// ПЕРЕГРУЗКИ
// iterator insert(iterator i, const T &val = T())
// вставляет элемент val перед элементом, на который указывает итератор i
// Возвращает итератор на только что вставленный элемент
// 
// void insert(iterator i, size_t num, const T& val)
// Вставляет num  элементов со значением val перед элементом на который указывает итератор i
// 
// template<class InIter>
// void insert(iterator i, InIter start, InIter end)
// Вставлчет в вектор последовательность определенную итераторами start end перед
// элементом на который указывает итератор
// 
// size_t max_size() const
// возвращает максимальное количество элементов которое может содеоржать вектор
// 
// реализация синтаксиса массива
// reference operator [] (size_t i)
// const reference operator[] (size_t)
// Возвращает ссылку на элемент заданный с помощью i 
// 
// void pop_back()
// Удаляет последний элемент
// 
// void push_back(const T& val)
// добавляет элемент сщ значением val в конец вектора
// 
// reverse_iterator rbegin()
// reverse_iterator rend()
// реверсивные итераторы
// 
// void reserve(size_t num)
// устанавливает емкость вектора, равную не менее num
// 
// template<class InIter>
// void reverse(InIter start, InIter end)
// Разворачивает последовательность между элементами
// на которые указывают итераторы start и end (меняет элементы местами)
//


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <char> v(3, '#');
	cout << v.at(4) << endl; // отлавливает ошибку



}

