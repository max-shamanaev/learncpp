#pragma once

#include "Creature.h"

#include "Random.h"

#include <array>

namespace game_q3
{
	class Monster : public Creature
	{
	public:
		enum Type
		{
			dragon,
			orc,
			slime,

			types_total
		};

		Monster(Type monsterType)
			: Creature{ getDefaultCreature(monsterType) }
		{

		}

		static Monster getRandomMonster()
		{
			return { static_cast<Type>(Random::get(0, types_total - 1)) };
		}

	private:
		static const Creature& getDefaultCreature(Type monsterType)
		{
			static const std::array<Creature, static_cast<size_t>(types_total)> monsterInfo{ {
				{ "dragon", 'D', 20, 4, 100 },
				{ "orc", 'o', 4, 2, 25 },
				{ "slime", 's', 1, 1, 10}
			} };

			return monsterInfo.at(static_cast<size_t>(monsterType));
		}
	};
}