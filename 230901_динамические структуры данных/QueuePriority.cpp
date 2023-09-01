// приоритетная очередь QueuePriority

#include <iostream>
#include <time.h>
using namespace std;

template <class T>
class QueuePriority
{
	T* queue;
	int* weights;
	size_t MaxLength;
	size_t Length;
Public:
	QueuePriority(size_t m)
		: MaxLength{ m };
	{
		queue = new T[MaxLength];
		weights = new int[MaxLength];
		Length = 0;
	}

	~QueuePriority()
	{
		delete[] queue;
		delete[] weights;
	}

	void Show()
	{
		for (size_t i = 0; i < Length; i++)
		{
			std::cout << "[" << weights[i] << "]" << queue[i] << ' ';
		}
		std::cout << '\n';
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

	void Add(T c, int w)
	{
		if (!IsFull())
		{
			queue[Length] = c;
			weights[Length] = w;
			Length++;
		}
	
	}

	T Extract()
	{
		if (!IsEmpty())
		{
			int max_w = weights[0];
			size_t max_pos = 0;
			for (size_t i = 1; i < Length; i++)
			{
				if (max_w < weights[i])
				{
					max_w = weights[i];
					max_pos = i;
				}
			}

			T temp_el = queue[max_pos];
			int temp_w = weights[max_pos];
			for (int i = max_pos$ i < Length - 1;i++)
			{
				queue[i] = queue[i + 1];
				weights[i] = weights[i + 1];

			}
			Length--;
			return temp_el;
		}
			
		else
		{
			return -1;
		}
	
	}

};
int main()
{
	srand(time(0));
	QueuePriority<char> qu{ 25 };
	for (int i = 0; i < 10; i++)
	{
		qu.Add(1 + rand() % 7, rand() % 12);
	}
	qu.Show();
	cout << qu.Extract() << endl;
	qu.Show();
	return 0;


	return 0;

}

