#include <iostream>

namespace q1
{
	int readNumber()
	{
		std::cout << "Please enter a number: ";
		int x{};
		std::cin >> x;
		return x;
	}

	void writeAnswer(int x)
	{
		std::cout << "The sum is: " << x << '\n';
	}

	void question1()
	{
		int x{ readNumber() };
		x = x + readNumber();
		writeAnswer(x);
	}
}

namespace q2
{
	int readNumber()
	{
		std::cout << "Please enter a number: ";
		int x{};
		std::cin >> x;
		return x;
	}

	void writeAnswer(int x)
	{
		std::cout << "The quotient is: " << x << '\n';
	}

	void question2()
	{
		int x{ };
		int y{ };
		x = readNumber();
		y = readNumber();
		writeAnswer(x / y);
	}
}

int main()
{
	q1::question1();
	q2::question2();

	/*Ответ на вопрос 3:
	*d()
	*b()
	*a()
	*main()
	*/

	return 0;
}