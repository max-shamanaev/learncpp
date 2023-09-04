#include "Card.h"
#include "Hand.h"

#include <iostream>

namespace Blackjack
{
	void Hand::addCard(const Card& card)
	{
		m_hand.push_back(card);

		// обработка случая, когда тузы могут быть равны 1/11
		if (m_score > 10 && card.getRank() == Card::rank_ace)
			m_score += 1;
		else
			m_score += card.getValue();

		if (m_score > 21)
			m_isOverdraw = true;
	}

	void Hand::print() const
	{
		for (const auto& card : m_hand)
		{
			card.print();
			std::cout << ' ';
		}
		std::cout << "(" << m_score << ")\n";
	}
}