/*
	�������� ����� ����� Fraction � �������������, ������� ��������� ��������� � �����������.
	���� ������������ �������� ����������� 0, ������������ ���������� ���� std::runtime_error
	(�������� � ��������� stdexcept). � ������� main() ��������� ������������ ������ ��� 
	����� �����. ���� ����� ����� ���������, �������� ��. ���� ����� �����������, �����������
	std::exception � �������� ������������, ��� �� ���� ������������ �����.

	�����:
	Enter the numerator: 5
	Enter the denominator: 0
	Invalid denominator
*/

#include <iostream>
#include <stdexcept>

class Fraction
{
public:
	Fraction(int num, int denom)
		: m_numerator{ num }, m_denominator{ denom }
	{
		if (denom == 0) 
			throw std::runtime_error{ "Invalid denominator" };
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << '/' << f.m_denominator;
		return out;
	}

private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };
};

int main()
{
	std::cout << "Enter the numerator: ";
	int numerator{};
	std::cin >> numerator;

	std::cout << "Enter the denominator: ";
	int denominator{};
	std::cin >> denominator;

	try
	{
		Fraction f{ numerator, denominator };
		std::cout << f << '\n';
	}
	catch (const std::exception& e)
	{
		//����������: std::cerr
		std::cout << e.what() << '\n';
	}

	return 0;
}