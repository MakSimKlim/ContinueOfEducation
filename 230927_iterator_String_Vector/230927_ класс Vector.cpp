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
// explicit vector(const Allocator &a = Allocator()) // явный конструктор, который всегда вызывается явно
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
//
//


#include <iostream>

int main()
{
}

