#pragma once

#include "Creature.h"

#include <iostream>
#include <string_view>

namespace game_q3
{
	class Player : public Creature
	{
	public:
		Player() = default;
		Player(std::string_view name)
			: Creature{ name, '@', 10, 1, 0 }
		{

		}

		void lvlUp()
		{
			++m_lvl;
			increaseDamage(1);
		}

		bool hasWon() const
		{
			return m_lvl >= 20;
		}

		int getLvl() const { return m_lvl; }

		friend std::ostream& operator<<(std::ostream& out, const Player& p)
		{
			std::cout << "(lvl: " << p.m_lvl << ", damage: " << p.m_damage << ", hp : " << p.m_hp << ")";
			return out;
		}

	private:
		int m_lvl{ 1 };
	};
}