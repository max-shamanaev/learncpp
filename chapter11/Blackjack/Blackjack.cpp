/*
	 арточна€ игра Blackjack
	(вопросы 6-7)

*/

#include "Card.h"
#include "Deck.h"
#include "Hand.h"

#include <cassert>
#include <iostream>
#include <vector>
#include <limits>

namespace Blackjack
{
	enum class GameResult
	{
		dealerWin = 0,
		playerWin,
		tie
	};

	GameResult findWinner(const Hand& pHand, const Hand& dHand)
	{
		int pScore = pHand.getScore();
		int dScore = dHand.getScore();

		// также предусматриваетс€ ситуаци€ перебора с обеих сторон,
		// (победа меньшей руки в таком случае) 
		if (pScore == dScore)
			return GameResult::tie;
		else if (pHand.isOverdrawn() || dHand.isOverdrawn()) 
			return (pScore < dScore) ? GameResult::playerWin : GameResult::dealerWin;
		else 
			return (pScore > dScore) ? GameResult::playerWin : GameResult::dealerWin;
	}

	void playerTurn(Deck& deck, Hand& playerHand)
	{
		char playerChoice{};
		while (playerChoice != 's' && playerHand.getScore() < 21)
		{			
			std::cout << "Your hand:\t";
			playerHand.print();

			std::cout << "Would you like to hit or stand? (h/s): ";
			std::cin >> playerChoice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (playerChoice == 'h')
				playerHand.addCard(deck.drawCard());

			// escape-коды дл€ стирани€ предыдущей строки из консоли
			// (дл€ более чистого вывода)
			std::cout << "\x1b[1A" << "\x1b[2K";
		}
	}

	void dealerTurn(Deck& deck, Hand& dealerHand)
	{
		while (dealerHand.getScore() < 17)
		{
			dealerHand.addCard(deck.drawCard());

			std::cout << "Dealer's hand:\t";
			dealerHand.print();
		}
	}

	void playBlackjack(Deck& deck)
	{
		Hand dealerHand{};
		dealerHand.addCard(deck.drawCard());

		Hand playerHand{};
		playerHand.addCard(deck.drawCard());
		playerHand.addCard(deck.drawCard());		
		
		std::cout << "Dealer's hand:\t";
		dealerHand.print();

		std::cout << "\n-----Your turn---------\n";
		playerTurn(deck, playerHand);

		std::cout << "\n-----Dealer's turn-----\n";
		dealerTurn(deck, dealerHand);

		std::cout << '\n';
		switch (findWinner(playerHand, dealerHand))
		{
		case GameResult::playerWin: 
			std::cout << "Congratulatuions! You won!\n";
			break;
		case GameResult::dealerWin:
			std::cout << "Unfortunately, dealer won.\n";
			break;
		case GameResult::tie:
			std::cout << "Game ended in a tie!\n";
			break;
		default:
			assert("findWinner() unexpected result!");
			break;
		}
	}

	void run()
	{
		std::cout	<< "**************************************************\n"
					<< "********************Blackjack*********************\n"
					<< "**************************************************\n";

		Deck gameDeck{};
		bool quit{ false };
		while (!quit)
		{
			gameDeck.shuffleDeck();

			std::cout << "\n--------------------------------------------------\n";
			playBlackjack(gameDeck);

			std::cout << "Would you like to continue? (y/n): ";
			if (std::cin.get() == 'n')
				quit = true;
		}

		std::cout << "\nThank you for playing!\n";
	}
}
