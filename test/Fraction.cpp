#include <iostream>
#include <numeric>

class Fraction
{
public:
	Fraction()
	{

	}

	Fraction(int num, int denom)
		: m_numerator{ num }, m_denominator{ denom }
	{
		if (m_denominator < 0)
		{
			m_numerator *= -1;
			m_denominator *= -1;
		}
		reduce();
	}

	void print()
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	void reduce()
	{
		auto gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	Fraction operator-()
	{
		return { -m_numerator, m_denominator };
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f, int val);
	friend Fraction operator*(int val, const Fraction& f);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
	friend std::istream& operator>>(std::istream& in, Fraction& f);
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);
	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);

private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };
};

// since all overloads create new Fraction (anonymously)
// they'll call constructor with reduce() in it.
// so we don't need to call reduce() in each overload!
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f, int val)
{
	return { f.m_numerator * val, f.m_denominator };
}

Fraction operator*(int val, const Fraction& f)
{
	return { f.m_numerator * val, f.m_denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	out << f.m_numerator << '/' << f.m_denominator;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
	in >> f.m_numerator;
	in.ignore(2, '/');
	in >> f.m_denominator;

	f.reduce();

	return in;
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator * f2.m_denominator < f2.m_numerator* f1.m_denominator);
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	return (f2 < f1);
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 > f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
	return !(f1 < f2);
}