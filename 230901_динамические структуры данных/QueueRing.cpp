//  ольцева€ очередь

#include "QueueRing.h"
#include <iostream>
#include <time.h>
using namespace std;

template <class T>
class QueueRing
{
	T* queue;
	size_t MaxLength;
	size_t Length;
public:
	QueueRing(size_t m)
		: MaxLength{ m }
	{
		queue = new T[MaxLength];
		Length = 0;
	}

	~QueueRing()
	{
		delete[] queue;
	}

	void Show()
	{
		for (size_t i = 0; i < Length; i++)
		{
			std::cout << queue[i] << ' ';
		}
	}
	void Clear()
	{
		Length = 0;
	}

	bool IsEmpty()
	{
		return Length == 0;
	}

	bool IsFull()
	{
		return Length == MaxLength;
	}

	int Size()
	{
		return Length;
	}

	void Add(T c)
	{
		if (!IsFull())
		{
			queue[Length++] = c;
		}
	
	}
	bool Extract() // не уменьшаем длину, а последний перезаписываем первым
	{
		if (!IsEmpty())
		{
			int t = queue[0];
			for (int i = 1; i < MaxLength; i++)
			{
				queue[i - 1] = queue[i];

			}
			queue[Length - 1] = t;
			return t;
		}
		else
		{
			return 0;
		}
	}




};

int main()
{
	srand(time(0));
	QueueRing<char> qr{ 20 };
	for (int i = 10; i >= 0; i--)
	{
		char t = 1 + rand() % 6;
		qr.Add(t);

	}
	qr.Show();
	cout << qr.Extract() << endl;
	qr.Show();
	return 0;

}

