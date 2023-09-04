#include "constants.h"
#include <iostream>

void printHeight(double fallHeight, int secElapsed)
{
	double currentHeight = fallHeight - (gForce * secElapsed * secElapsed / 2.0);
	if (currentHeight > 0.0)
		std::cout << "At " << secElapsed << " seconds, the ball is at height: " << currentHeight << '\n';
	else
		std::cout << "At " << secElapsed << " seconds, the ball is on the ground.\n";
}

void question4()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height;
	std::cin >> height;

	printHeight(height, 0);
	printHeight(height, 1);
	printHeight(height, 2);
	printHeight(height, 3);
	printHeight(height, 4);
	printHeight(height, 5);
}