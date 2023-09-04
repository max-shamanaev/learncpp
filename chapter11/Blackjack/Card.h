#pragma once

namespace Blackjack
{
	class Card
	{
	public:
		enum Rank
		{
			rank_2 = 2,
			rank_3,
			rank_4,
			rank_5,
			rank_6,
			rank_7,
			rank_8,
			rank_9,
			rank_10,
			rank_jack,
			rank_queen,
			rank_king,
			rank_ace,

			ranks_total,
		};

		enum Suit
		{
			clubs,
			diamonds,
			hearts,
			spades,

			suits_total,
		};

		Card() = default;
		Card(Rank rank, Suit suit) : m_rank{ rank }, m_suit{ suit }
		{
		}

		void print() const;
		int getValue() const;
		Rank getRank() const { return m_rank; }

	private:
		Rank m_rank{};
		Suit m_suit{};
	};
}
