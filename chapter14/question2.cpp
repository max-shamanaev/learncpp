/*
	�������� ����� � ������ Average, ������� ����� ����������� ������� �������� 
	���� ���������� ��� ����� �����. ����������� ��� �����: ������ ������ ����� 
	��� std::int_least32_t � �������������� ��� ������������ ����� ���� �����, 
	������� �� ������ �� ������ ������. ������ ������ ����� ��� std::int_least8_t 
	� �������������� ��� ������������ ����, ������� ����� �� ��� ������. �� ������ 
	��������� ��, ����� ����� ������� ��������.

	2b) ����� �� ����� ������ ����� ����������� ����������� � �������� ������������?
	����� - ���; ����� �� ������������� ���������� ����������� ���������� �������
	��� ���������, ��� ��� ��������������� ������� ����������� ����������� �
	�������� ������������ ������������� ������������
*/

#include <cstdint>
#include <iostream>

class Average
{
public:
	Average() {}
	friend std::ostream& operator<<(std::ostream& out, const Average& avg);
	Average& operator+=(int val);

private:
	std::int32_t m_sum{ 0 };
	std::int8_t  m_count{ 0 };
};

Average& Average::operator+=(int val)
{
	m_sum += val;
	++m_count;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	out << static_cast<double>(avg.m_sum) / static_cast<double>(avg.m_count);
	return out;
}

void question2()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';
}