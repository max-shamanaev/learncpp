/*
	В этом тесте мы собираемся написать класс для реализации числа с фиксированной
	запятой с двумя цифрами в дробной части (например, 12.34, 3.00 или 1278.99). 
	Предположим, что диапазон значений класса должен быть от -32768.99 до 32767.99, 
	что дробная часть должен содержать любые две цифры, что нам не нужны ошибки 
	точности, и что мы хотим сэкономить место.
*/

#include <cstdint>
#include <cmath>
#include <iostream>

class FixedPoint2
{
public:
	FixedPoint2() = default;
	FixedPoint2(std::int16_t base, std::int8_t decimal = 0);
	FixedPoint2(double val);

	operator double() const;
	bool operator==(const FixedPoint2& other) const;
	FixedPoint2 operator-() const;

	//Дополнение: не должна быть friend, т.к. не требует доступа к закрытым полям
	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2 fp);

	friend FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2);

private:
	std::int16_t m_base{ 0 };
	std::int8_t m_decimal{ 0 };
};

FixedPoint2::FixedPoint2(std::int16_t base, std::int8_t decimal)
	: m_base{ base }, m_decimal{ decimal }
{
//	assert(decimal > -99 && decimal < 99);
	if (m_decimal > 99)
	{
		m_base += 1;
		m_decimal %= 99;
	}
	else if (m_decimal < -99)
	{
		m_base -= 1;
		m_decimal %= 99;
	}
}

FixedPoint2::FixedPoint2(double val) 
	//Дополнение:
	// : m_base{ static_cast<std::int16_t>(std::trunc(d)) },
	//   m_decimal { static_cast<std::int8_t>(std::round(d * 100) - m_base * 100) }
{
	int factored = std::round(val * 100);
	m_base = static_cast<std::int16_t>(factored / 100);
	m_decimal = static_cast<std::int8_t>(factored % 100);
}

FixedPoint2::operator double() const
{
	double val{ std::abs(m_base) + std::abs(static_cast<double>(m_decimal) / 100) };
	if (m_base < 0 || m_decimal < 0)
		return -val;
	else
		return val;
}

bool FixedPoint2::operator==(const FixedPoint2& other) const
{
	return (m_base == other.m_base && m_decimal == other.m_decimal);
}

FixedPoint2 FixedPoint2::operator-() const
{
	// Дополнение:
	// Нам нужно приведение, потому что отрицательный знак (-)
	// преобразует наши узкие целочисленные типы в int.
	//	return {
	//		static_cast<std::int_least16_t>(-m_base),
	//		static_cast<std::int_least8_t>(-m_decimal)
	//	};

	return { -m_base, -m_decimal };
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
	return static_cast<double>(fp1) + static_cast<double>(fp2);
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2 fp)
{
	out << static_cast<double>(fp);
	return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp)
{
	double val{};
	in >> val;
	fp = FixedPoint2(val);

	return in;
}

void testAddition()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

void question4()
{
	FixedPoint2 a{ 0.01 };
	std::cout << a << '\n';

	FixedPoint2 b{ -0.01 };
	std::cout << b << '\n';

	FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
	std::cout << e << '\n';

	FixedPoint2 f{ 1.9 }; // make sure we handle single digit decimal
	std::cout << f;

	std::cout << "\n-------------------------------\n";

	testAddition();

	FixedPoint2 x{ -0.48 };
	std::cout << x << '\n';

	std::cout << -x << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> x;

	std::cout << "You entered: " << x << '\n';
}