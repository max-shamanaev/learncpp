#include <iostream>

double getDouble()
{
	std::cout << "Enter a double value: ";
	double num;
	std::cin >> num;

	return num;
}

char getOperation()
{
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char op;
	std::cin >> op;

	return op;
}

double calculate(double a, double b, char op)
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;

	return INFINITY;
}

void question3()
{
	double a{ getDouble() };
	double b{ getDouble() };
	char op{ getOperation() };

	double res = calculate(a, b, op);
	if (res != INFINITY)
		std::cout << a << ' ' << op << ' ' << b << " is " << res;
}