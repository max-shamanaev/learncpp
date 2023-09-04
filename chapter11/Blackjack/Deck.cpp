#include "Card.h"
#include "Deck.h"

#include "Random.h"

#include <algorithm>
#include <cassert>
#include <iostream>

namespace Blackjack
{
	Deck::Deck()
	{
		for (int suit{ 0 }, cardCount{ 0 }; suit < Card::suits_total; ++suit)
		{
			for (int rank{ 2 }; rank < Card::ranks_total; ++rank, ++cardCount)
			{
				m_deck[cardCount] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
			}
		}

		shuffleDeck();
	}

	void Deck::shuffleDeck()
	{
		std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
		m_topDeck = m_deck.begin();
	}

	void Deck::printDeck() const
	{
		for (const auto& card : m_deck)
		{
			card.print();
			std::cout << ' ';
		}
		std::cout << '\n';
	}

	const Card& Deck::drawCard()
	{
		assert(m_topDeck != m_deck.end() && "Run out of cards during the round!!");
		return *m_topDeck++;
	}
}