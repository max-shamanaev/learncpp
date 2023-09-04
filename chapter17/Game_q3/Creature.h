#pragma once

#include <string>
#include <string_view>

namespace game_q3
{
	class Creature
	{
	public:
		Creature() = default;
		Creature(std::string_view name, char ch, int hp, int damage, int gold)
			: m_name{ name }, m_symbol{ ch }, m_hp{ hp }
			, m_damage{ damage }, m_gold{ gold }
		{

		}

		void addGold(int val)
		{
			m_gold += val;
		}

		// Заметка: не предусматривает максимально возможные хп
		// для существа
		void restoreHealth(int val)
		{
			m_hp += val;
		}

		void reduceHealth(int val)
		{
			m_hp -= val;
		}

		void increaseDamage(int val)
		{
			m_damage += val;
		}

		bool isDead() const
		{
			return m_hp <= 0;
		}

		std::string_view getName() const { return m_name; }
		char getSymbol() const { return m_symbol; }
		int getHp() const { return m_hp; }
		int getDamage() const { return m_damage; }
		int getGold() const { return m_gold; }

	protected:
		std::string m_name{};
		char m_symbol{};
		int m_hp{};
		int m_damage{};
		int m_gold{};
	};
}