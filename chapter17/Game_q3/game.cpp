/*
	Мы собираемся написать простую игру, в которой вы сражаетесь с монстрами. 
	Цель игры – собрать как можно больше золота перед смертью или достижением 20 уровня.

	Наша программа будет состоять из 3 классов: класса Creature (существо), класса Player
	(игрок) и класса Monster (монстр). И Player, и Monster наследуются от Creature.
*/

#include "Creature.h"
#include "Player.h"
#include "Potion.h"
#include "Monster.h"

#include "Random.h"

#include <iostream>

namespace game_q3
{
	void drinkPotion(Player& player, const Potion& potion)
	{
		int changeValue{ potion.getStatChangeValue() };
		switch (potion.getType())
		{
		case Potion::health:
			player.restoreHealth(changeValue);
			break;
		case Potion::poison:
			player.reduceHealth(changeValue);
			break;
		case Potion::strength:
			player.increaseDamage(changeValue);
			break;
		default:
			assert("PLAYER DRUNK UNKOWN POTION");
			break;
		}

		std::cout << "You drank a " << potion << ".\n";
	}

	void attackMonster(Player& player, Monster& monster)
	{
		monster.reduceHealth(player.getDamage());
		std::cout << "You hit the " << monster.getName() << " for "
			<< player.getDamage() << " damage.\n";

		if (monster.isDead())
		{
			player.lvlUp();
			player.addGold(monster.getGold());

			std::cout << "You killed the " << monster.getName() << ".\n"
				<< "You found " << monster.getGold() << " gold.\n";
		}
	}

	void attackPlayer(Player& player, const Monster& monster)
	{
		player.reduceHealth(monster.getDamage());
		std::cout << "The " << monster.getName() << " hit you for "
			<< monster.getDamage() << " damage.\n";
	}

	void fightMonster(Player& player, Monster& monster)
	{
		std::cout << "\nYou have encountered a " << monster.getName()
			<< '(' << monster.getSymbol() << ").\n"
			<< "Your stats are: " << player << "\n\n";

		while (!monster.isDead() && !player.isDead())
		{
			char pChoice{};
			do
			{
				std::cout << "(R)un or (F)ight: ";
				std::cin >> pChoice;
			} while (pChoice != 'R' && pChoice != 'r' && pChoice != 'F' && pChoice != 'f');

			if (pChoice == 'R' || pChoice == 'r')
			{
				if (Random::get(0, 1) == 1)
				{
					std::cout << "You successfully fled.\n";
					return;
				}
				else
				{
					std::cout << "You failed to flee.\n";
					attackPlayer(player, monster);
				}
			}
			else
			{
				attackMonster(player, monster);

				if (!monster.isDead())
					attackPlayer(player, monster);
			}
		}
	}

	void playGame(Player& player)
	{
		while (!player.isDead() && !player.hasWon())
		{
			Monster monster{ Monster::getRandomMonster() };
			fightMonster(player, monster);

			if (!player.isDead() && monster.isDead() && Random::get(1, 100) <= 30)
			{
				std::cout << "You found a mythical potion! Do you want to drink it? (y/n): ";
				char pChoice{};
				std::cin >> pChoice;

				if (pChoice == 'y')
					drinkPotion(player, Potion::getRandomPotion());
			}
		}
	}

	void run()
	{
		std::cout << "Enter your name: ";
		std::string name{};
		std::cin >> name;

		std::cout << "Welcome, " << name << ".\n";

		bool quit{ false };
		while (!quit)
		{
			std::cout << "--------------------";

			Player player{ name };
			playGame(player);

			if (player.hasWon())
				std::cout << "You have completed the game with " << player.getGold() << " gold!\n";
			else
				std::cout << "You died at level " << player.getLvl() << " and with "
				<< player.getGold() << " gold.\n";

			std::cout << "Want to try again? (y/n) ";
			char restart{};
			std::cin >> restart;

			if (restart == 'n')
				quit = true;
		}
	}
}