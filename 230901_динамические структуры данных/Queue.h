//#pragma once
//#include <iostream>
//template <class T>
//class Queue
//{
//	T* queue;
//	size_t MaxLength;
//	size_t Length;
//public:
//	Queue(size_t m)
//		: MaxLength{ m }
//	{
//		queue = new T[MaxLength];
//		Length = 0;
//	}
//
//	~Queue()
//	{
//		delete[] queue;
//	}
//
//	void Clear()
//	{
//		Length = 0;
//	}
//
//	bool IsEmpty()
//	{
//		return Length == 0;
//	}
//
//	bool IsFull()
//	{
//		return Length == MaxLength;
//	}
//
//	int Size()
//	{
//		return Length;
//	}
//
//	void Add(T c)
//	{
//		if (!IsFull())
//		{
//			queue[Length++] = c;
//		}
//	}
//
//	// ����� ���������� �� �������
//	T Extract() // ������� ������ ������� ������� ��� �� ������� � ������� �� ��������� �������
//	{
//		if (!IsEmpty())
//		{
//			T temp = queue[0];
//			for (int i = 0; i < Length; i++)
//			{
//				queue[i - 1] = queue[i];
//			}
//			Length--;
//			return temp;
//		}
//		else // ���� � ����� ��� ���������
//		{
//			return -1;
//		}
//	}
//	void Show()
//	{
//		for (size_t i = 0; i < Length; i++)
//		{
//			std::cout << queue[i] << ' ';
//		}
//	}
//
//};
//
