#include "constants.h"
#include <iostream>

double calculateHeight(double initialHeight, int secElapsed)
{
	double currentHeight = initialHeight - (constants::gForce * secElapsed * secElapsed / 2.0);
	return (currentHeight > 0.0) ? currentHeight : 0.0;
}

void question1()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height;
	std::cin >> height;

	for (int timeSec{0};; ++timeSec)
	{
		double currentHeight{ calculateHeight(height, timeSec) };
		if (currentHeight != 0.0)
			std::cout << "At " << timeSec << " seconds, the ball is at height: "
			<< calculateHeight(height, timeSec) << '\n';
		else
		{
			std::cout << "The ball hit the ground at " << timeSec << " seconds.\n";
			break;
		}
	}
	
	/*
	int sec{ 0 };
	double currentheight{ height };
	while (currentheight > 0.0)
	{
		currentheight = calculateHeight(height, sec);
		std::cout << "At " << sec << " seconds, the ball is at height: "
			<< currentheight << '\n';

		if (currentheight != 0.0)
			++sec;
	}
	std::cout << "The ball hit the ground at " << sec << " seconds.\n";
	*/
}