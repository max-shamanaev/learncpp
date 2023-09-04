/*
	Напишите свою собственную функцию для обмена значениями двух целочисленных переменных.
	Напишите функцию main(), чтобы проверить ее.
*/

#include <iostream>

void swap(int& a, int& b)
{
	int temp{ a };
	a = b;
	b = temp;
}

void question3()
{
	int a{ 5 };
	int b{ 8 };
	
	std::cout << "Before swap: " << a << ' ' << b << '\n';
	
	swap(a, b);

	std::cout << "After swap: " << a << ' ' << b << '\n';
}