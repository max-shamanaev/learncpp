/*

5a) �������� ������ ������� � ������ add, ������� ��������� ������������� ���������� 2 �������� ������ ����. 
5b) �������� ������ ������� � ������ mult, ������� ��������� ������������ �������� ���� �������� ������ ���� �� ����� int.
5c) �������� ������ ������� � ������ sub, ������� ��������� ������������ �������� ��� �������� ������ �����.

*/

#include <iostream>

template<typename T>
T add(T a, T b)
{
	return a + b;
}

template<typename T>
T mult(T a, int b)
{
	return a * b;
}

template<typename T, typename U>
auto sub(T a, U b)
{
	return a - b;
}

void question5()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	std::cout << '\n';

	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	std::cout << '\n';

	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';
}