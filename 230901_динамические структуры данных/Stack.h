//#pragma once
//#include <iostream>
//template <class T>
//class Stack
//{
//	// ���������� ����� ����������� ������
//	enum {EMPTY = -1, FULL = 20};
//	T st[FULL + 1];
//	//T* top; - ��������� �� �������, ��� ������� ����� ���������
//	int top;
//
//public:
//	Stack()
//	{
//		top = EMPTY;
//	
//	};
//	void Push(T c)
//	{
//		if (!IsFull())
//		{
//			st[++top] = c;
//		}
//	};
//	T Pop()
//	{
//		if (IsEmpty())
//		{
//			return 0;
//		}
//		else
//		{
//			return st[top--];
//		}
//	
//	};
//	void Clear()
//	{
//		top = EMPTY;
//
//	};
//	bool IsEmpty()
//	{
//		return top == EMPTY;
//	
//	};
//	bool IsFull()
//	{
//		return top == FULL;
//
//	
//	};
//	size_t Size()
//	{
//		return top + 1;
//	};
//
//
//
//};
//
