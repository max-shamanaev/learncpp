/*
	���� ������-�������� � ��� ������ ��� ����, ��� ������ �������� ������ �������� 
	��������� �����, � ������ �������� ����� ���� ������ ����. �������� ������ ������
	� ������ StringValuePair, ������� ����������� �� �������� ������������������� 
	������ Pair (������������� std::string � �������� ������� ���� � ������������ 
	������������ ������� ������ ���).
*/

#include "Pair.h"

#include <iostream>
#include <string>

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& str, const T& val)
		: Pair<std::string, T>{ str, val }
	{

	}
};

void question3()
{
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}