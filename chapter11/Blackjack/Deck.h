#pragma once

#include "Card.h"

#include <array>
#include <cstddef>

namespace Blackjack
{
	class Deck
	{
	public:
		Deck();
		void shuffleDeck();
		void printDeck() const;
		const Card& drawCard();

	private:
		static constexpr size_t s_cardsTotal{ 52 };
		std::array<Card, s_cardsTotal> m_deck{};
		std::array<Card, s_cardsTotal>::iterator m_topDeck{};
	};
}
