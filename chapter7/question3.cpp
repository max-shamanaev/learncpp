#include <limits>
#include <iostream>
#include <random>

namespace gameconfig
{
	constexpr int guesses{ 7 };
	constexpr int boundMin{ 0 };
	constexpr int boundMax{ 200 };
}

int getGuess(int boundMin, int boundMax)
{
	while (true)
	{
		int guess{};
		std::cin >> guess;

		if (!std::cin)
		{
			if (std::cin.eof())
				exit(0);

			std::cin.clear();
		}

		if (guess >= boundMin && guess <= boundMax)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return guess;
		}
		else
		{
			std::cout << "Invalid input! Enter your guess again: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

bool playHiLo(int number, int guesses)
{
	for (int i{ 1 }; i <= guesses; ++i)
	{
		std::cout << "Guess #" << i << ": ";
		int guess{ getGuess(gameconfig::boundMin, gameconfig::boundMax) };

		if (guess == number)
			return true;

		if (guess > number)
			std::cout << "Your guess is too high.\n";
		else
			std::cout << "Your guess is too low.\n";
	}

	return false;
}

bool isRetry()
{
	char option{};
	do
	{
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> option;
	} while (option != 'y' && option != 'n');

	return (option == 'y');
}

void question3()
{
	std::random_device rd{};
	std::seed_seq seeds{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 rng{ seeds };
	std::uniform_int_distribution rndNum{ gameconfig::boundMin, gameconfig::boundMax };

	do
	{
		std::cout << "Let's play a game. I'm thinking of a number between " 
			<< gameconfig::boundMin << " and " << gameconfig::boundMax 
			<< ". You have " << gameconfig::guesses << " tries to guess what it is.\n";

		int number = rndNum(rng);
		bool isWon{ playHiLo(number, gameconfig::guesses) };
		
		if (isWon)
			std::cout << "Correct! You won!\n";
		else
			std::cout << "Sorry, you lost. The correct number was " << number << ".\n";

	} while (isRetry());

	std::cout << "Thank you for playing.";
}