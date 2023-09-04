/*
	Create a class template named Triad that has 3 members of the same template type. 
	Also create a function template named print that can print a Triad.

	Output:
	[1, 2, 3][1.2, 3.4, 5.6]
*/

#include <iostream>

template <typename T>
struct Triad
{
	T first{};
	T second{};
	T third{};
};

//C++17
template <typename T>
Triad(T, T, T)->Triad<T>;

template <typename T>
void print(const Triad<T>& triad)
{
	std::cout << "[" << triad.first << ", " << triad.second
		<< ", " << triad.third << "]";
}

void question3()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);
}