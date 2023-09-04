#include <iostream>

using namespace std;
int main()
{
	int a{}, b{};
	cout << "Enter an integer: ";
	cin >> a;
	cout << "Enter another integer: ";
	cin >> b;

	cout << a << " + " << b << " is " << a + b << ".\n";
	cout << a << " - " << b << " is " << a - b << ".\n";

	return 0;
}