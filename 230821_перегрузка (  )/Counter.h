#pragma once
class Counter
{
	int cnt;
public:
	Counter(int start) : cnt{ start } {};
	Counter() : Counter(0) {};
	int resetTo(int start = 0) { cnt = start; }
	}
	int operator()() { return cnt++; }

};

