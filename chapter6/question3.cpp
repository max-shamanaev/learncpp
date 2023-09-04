#include <iostream>

int accumulate(int x)
{
	static int s_sum{ 0 };
	s_sum += x;
	return s_sum;
}

bool passOrFail()
{
	static int s_callNum{ 0 };
	++s_callNum;
	
	return s_callNum <= 3;
}

void question3()
{
	/*
	std::cout << accumulate(4) << '\n'; // prints 4
	std::cout << accumulate(3) << '\n'; // prints 7
	std::cout << accumulate(2) << '\n'; // prints 9
	std::cout << accumulate(1) << '\n'; // prints 10
	*/
	
	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
}