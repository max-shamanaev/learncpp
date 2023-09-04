#include <functional>
#include <iostream>

int getUserInt()
{
	std::cout << "Enter an integer: ";
	int inp{};
	do
	{
		std::cin >> inp;
		if (std::cin.fail())
		{
			std::cout << "Invalid input! Try again: ";
			std::cin.clear();
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} 
	while (!inp);

	return inp;
}

char getUserOp()
{
	char inp{};
	do
	{
		std::cout << "Enter operation to perform (+, -, *, /): ";
		std::cin >> inp;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} 
	while (inp != '+' && inp != '-' && inp != '*' && inp != '/');

	return inp;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+':	return add;
	case '-':	return subtract;
	case '*':	return multiply;
	case '/':	return divide;
	default:	return nullptr;
	}
}

void quiz12_1()
{
	int x{ getUserInt() };
	int y{ getUserInt() };
	char op{ getUserOp() };

	ArithmeticFunction operationFcn{ getArithmeticFunction(op) };

	if (operationFcn) // don't forget to check nullptr!
		std::cout << "Result is: " << operationFcn(x, y);
}