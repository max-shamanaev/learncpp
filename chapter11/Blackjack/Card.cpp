#include "Card.h"

#include <iostream>

namespace Blackjack
{
	void Card::print() const
	{
		std::string str{ "" };

		switch (m_rank)
		{
		case rank_2:		str += "2";		break;
		case rank_3:		str += "3";		break;
		case rank_4:		str += "4";		break;
		case rank_5:		str += "5";		break;
		case rank_6:		str += "6";		break;
		case rank_7:		str += "7";		break;
		case rank_8:		str += "8";		break;
		case rank_9:		str += "9";		break;
		case rank_10:		str += "T";		break;
		case rank_jack:		str += "J";		break;
		case rank_queen:	str += "Q";		break;
		case rank_king:		str += "K";		break;
		case rank_ace:		str += "A";		break;
		default:			str += "UNK_";	break;
		}

		switch (m_suit)
		{
		case clubs:		str += "C";		break;
		case diamonds:	str += "D";		break;
		case hearts:	str += "H";		break;
		case spades:	str += "S";		break;
		default:		str += "UNK";	break;
		}

		std::cout << str;
	}

	int Card::getValue() const
	{
		switch (m_rank)
		{
		case rank_2:		return 2;
		case rank_3:		return 3;
		case rank_4:		return 4;
		case rank_5:		return 5;
		case rank_6:		return 6;
		case rank_7:		return 7;
		case rank_8:		return 8;
		case rank_9:		return 9;
		case rank_10:		return 10;
		case rank_jack:		return 10;
		case rank_queen:	return 10;
		case rank_king:		return 10;
		case rank_ace:		return 11;
		default:			return 0;
		}
	}
}