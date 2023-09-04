#include <iostream>

// нет проверки на нулевой указатель
// возможно переполнение

void foo(int* a, int l)
{
	for (int i = 0; i < l; i++)
		a[i] = a[i] + a[i];
}

int main()
{
	int arr[7]{ 2,4,6,8,10,12,14 };

	foo(arr, 7);

	for (auto el : arr)
		std::cout << el << ' ';

	return 0;
}