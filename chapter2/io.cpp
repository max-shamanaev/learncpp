#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Enter an integer to add: ";
	int num{};
	std::cin >> num;

	return num;
}

void writeAnswer(int num)
{
	std::cout << "The answer is: " << num << '\n';
}