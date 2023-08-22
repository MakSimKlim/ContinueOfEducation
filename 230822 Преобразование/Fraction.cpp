#include"Fraction.h"
int Fraction::gcd(int a, int b)
{
	int c;
	while (b)
	{
		a %= b;
		c = a;
		a = b;
		b = c;
	}
	return  a;
}
void Fraction::reduce()
{
	int gcdVal{ gcd(num, den) };
	num /= gcdVal;
	den /= gcdVal;
	if (num < 0 && den < 0)
	{
		den *= -1;
		num *= -1;
	}

}
void Fraction::print() const
{
	std::cout << "(" << num << "/" << den << ")";

};
Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction{
		left.GetNumerator() * right.GetDenomerator() +
		right.GetNumerator() * left.GetDenomerator(),
		left.GetNumerator() * right.GetDenomerator()
	};
}
// Дружественная функция
//Fraction operator+(const Fraction& left, const Fraction& right)
//{
//	return Fraction{
//		left.num * right.den +
//		right.num * left.den,
//		left.num * right.den
//	};
//}
//// Дружественная функция
//Fraction operator+(const Fraction& left, int right)
//{
//	return Fraction{
//		left.den + right *
//		left.num,
//		left.den
//	};
//}

Fraction operator+(const Fraction& left, int right)
{
	return Fraction{
		left.GetDenomerator() + right *
		left.GetNumerator(),
		left.GetDenomerator()
	};
}

Fraction operator+(int left, const Fraction& right)
{
	return right + left;
}

