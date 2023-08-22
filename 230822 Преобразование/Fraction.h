#pragma once
#include <iostream>

class Fraction
{
	int num;
	int den;
	int gcd(int a, int b); //НОЗ
	void reduce(); // сокращение дроби
public:
	Fraction(int numP, int denP) : num{ numP }, den{ denP ? denP : 1 }
	{
		reduce();
	}
	Fraction() :Fraction(1, 1) {};

	void SetNumerator(int numP) { num = numP; reduce(); }
	void SetDenomerator(int denP) { den = denP ? denP : 1; reduce(); }
	int GetNumerator() const { return num; }
	int GetDenomerator() const { return den; }
	void print() const;

	// Дружественные функции
	// friend SetNumerator(int numP) { num = numP; reduce(); }
	// friend SetDenomerator(int denP) { den = denP ? denP : 1; reduce(); }
	// friend GetNumerator() const { return num; }
	// friend GetDenomerator() const { return den; }

};

