#pragma once

#include "Card.h"

#include <vector>

namespace Blackjack
{
	class Hand
	{
	public:
		Hand(){}
		void addCard(const Card& card);
		void print() const;
		int getScore() const { return m_score; }
		bool isOverdrawn() const { return m_isOverdraw; }

	private:
		std::vector<Card> m_hand{};
		int m_score{ 0 };
		bool m_isOverdraw{ false };
	};
}