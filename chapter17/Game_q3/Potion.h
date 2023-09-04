#pragma once

#include "Random.h"

#include <cassert>
#include <iostream>
#include <map>
#include <string>

namespace game_q3
{
	class Potion
	{
	public:
		enum Type
		{
			health,
			strength,
			poison,

			types_total
		};

		enum Size
		{
			small,
			medium,
			large,

			sizes_total
		};

		Potion() = default;
		Potion(Type type, Size size)
			: m_type{ type }, m_size{ size }
		{
			assert(type != types_total);
			assert(size != sizes_total);
		}

		static Potion getRandomPotion() 
		{
			auto rndType{ static_cast<Type>(Random::get(0, types_total - 1)) };
			auto rndSize{ static_cast<Size>(Random::get(0, sizes_total - 1)) };

			return { rndType, rndSize };
		}

		int getStatChangeValue() const
		{
			int constexpr base{ 1 };
			return base * getMultiplier(m_size);
		}

		friend std::ostream& operator<<(std::ostream& out, const Potion& p)
		{
			switch (p.m_size)
			{
			case small:		out << "Small "; break;
			case medium:	out << "Medium "; break;
			case large:		out << "Large "; break;
			default:		out << "UNKNOWN "; break;
			}

			out << "potion of ";

			switch (p.m_type)
			{
			case health:	out << "Health"; break;
			case strength:	out << "Strength"; break;
			case poison:	out << "Poison"; break;
			default:		out << "UNKOWN"; break;
			}

			return out;
		}

		Type getType() const { return m_type; }
		Size getSize() const { return m_size; }

	private:
		static int getMultiplier(Size size)
		{
			static const std::map<Size, int> s_sizeMultiplier
			{ 
				{small, 1}, 
				{medium, 2}, 
				{large, 4} 
			};

			return s_sizeMultiplier.at(size);
		}
		
		Type m_type{};
		Size m_size{};
	};
}