/*
	��� �� ��� � ������ �� ���� ���������� ����, � ��� ��� ���������?
*/

#include <cstddef>
#include <iostream>

// 5a)
int a()
{
	int array[]{ 0, 1, 2, 3 };

	// ������ �� ������� ��-�� ������������� �������
	//for (std::size_t count{ 0 }; count <= std::size(array); ++count)
	//{
	//	std::cout << array[count] << ' ';
	//}

	for (std::size_t count{ 0 }; count < std::size(array); ++count)
	{
		std::cout << array[count] << ' ';
	}

	std::cout << '\n';

	return 0;
}

// 5b)
int b()
{
	int x{ 5 };
	int y{ 7 };

	const int* ptr{ &x };
	std::cout << *ptr << '\n';

	// ��������� �������� ��������� �� ����������� int
	//*ptr = 6;
	//
	// ���� - ������ ����������� const

	std::cout << *ptr << '\n';
	ptr = &y;
	std::cout << *ptr << '\n';

	return 0;
}

// 5c)
void printArray(int array[])
{
	// ������ ���������� �� ��������� ��� �������� ��� � �������
	// => �� ����� ���������� � ��� �����
	// => for-each �� ����� ����������� ������
	//for (int element : array)
	//{
	//	std::cout << element << ' ';
	//}
}

void printArrayFixed(const int* arr, const int l)
{
	for (int i{ 0 }; i < l; ++i)
		std::cout << arr[i] << ' ';
}

int c()
{
	int array[]{ 9, 7, 5, 3, 1 };

	//printArray(array);
	printArrayFixed(array, std::ssize(array));

	std::cout << '\n';

	return 0;
}

// 5d)
// ������� ��������� �� �������� ��������� ������
// => �������� ������� ���������, �.�. temp ����� ��������� �� ���������� �������
// (��� �� ������ ������� ������������� ������ � ������, ������������ �� �� ����� ��������������)
//
//int* allocateArray(const int length)
//{
//	int temp[length]{};
//	return temp;
//}

int* allocateArrayFixed(const int length)
{
	return new int[length] {};
}

//5e)
int e()
{
	double d{ 5.5 };

	//������������� ��������� �� int ������� ��������� �� double
	//int* ptr{ &d };
	
	double* ptr{ &d };

	std::cout << *ptr << '\n';

	return 0;
}