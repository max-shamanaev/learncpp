#include "Random.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void quiz12_8()
{
	std::cout << "Start where? ";
	int numStart{};
	std::cin >> numStart;

	std::cout << "How many? ";
	int count{};
	std::cin >> count;

	std::vector<int> v;
	int randInt{ Random::get(2,4) };
	for (int i{ 0 }; i < count; ++i, ++numStart)
	{
		v.push_back((numStart * numStart) * randInt);
	}

	std::cout << "I generated " << count << " square numbers. Dou you know what "
		<< "each number is after multiplying it by " << randInt << "?\n";

	int guess{};
	bool isWrong{ false };
	while (!isWrong)
	{
		std::cout << "> ";
		std::cin >> guess;

		auto found{ std::find(v.begin(), v.end(), guess) };

		if (found != v.end())
		{
			v.erase(found);

			if (v.size() == 0)
				break;

			std::cout << "Nice! " << v.size() << " number(s) left.\n";
		}
		else
		{
			isWrong = true;
			std::cout << guess << " is wrong! ";

			auto closest{ std::find_if(v.begin(), v.end(), 
				[=](int vecNum)
				{
					return std::abs(guess - vecNum) <= 4;
				}
			)};

			// find_if will return the FIRST element matching the criteria, even if there is a "better" match later.
			// Using min_element ensures we always find the number that is closest.
			// For example, if the generated numbers are 2, 8, 18, and the user guesses 6, find_if will match 2 even though 8 is closer.
			auto closestMin{ std::min_element(v.begin(), v.end(),
				[=](int a, int b)
				{
					return std::abs(a - guess) < std::abs(b - guess);
				}
			)};

			if (closest != v.end())
				std::cout << "Try " << *closest << " next time.\n";
			else
				std::cout << '\n';
		}
	}

	if (!isWrong)
		std::cout << "Nice! You found all numbers, good job!\n";
}