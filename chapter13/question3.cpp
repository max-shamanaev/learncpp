/*
	√енератор случайных монстров
*/

#include "Random.h"

#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
	enum Type
	{
		dragon = 0,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
	
		max_monster_types
	};

	Monster(Type type, std::string_view name, std::string_view roar, int hp)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hp{ hp }
	{

	}

	std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case dragon:	return "dragon";
		case goblin:	return "goblin";
		case ogre:		return "ogre";
		case orc:		return "orc";
		case skeleton:	return "skeleton";
		case troll:		return "troll";
		case vampire:	return "vampire";
		case zombie:	return "zombie";
		default:		return "UKNOWN_MONSTER_TYPE";
		}
	}

	void print() const
	{
		std::cout << m_name << " the " << getTypeString()
			<< " has " << m_hp << " hit points"
			<< " and says " << m_roar << '\n';
	}

private:
	Type		m_type{};
	std::string m_name{};
	std::string m_roar{};
	int			m_hp{};
};

// learncpp задание - 
// <..>We donТt need more than one monster generator, 
// and we are not maintaining any state, so this is a 
// good candidate for a namespace. 
// Create a namespace named MonsterGenerator.<..>
//
// стара€ верси€ - создание статического класса
namespace MonsterGenerator
{
	// решил сделать массивы глобальными константами, т.к.
	// 
	// 1) уже присутствует отведенное пространство имен (по заданию)
	// 
	// 2) таким образом напр€мую можно получить к ним read-only доступ,
	// что может быть удобно
	// 
	// 3) (из п.2) логичней их вынести за предели функции generate() в виду 
	// возможного добавлени€ функционала в данный namespace, работающего
	// непосредственно/косвенно с этими массивами
	constexpr std::array namesAll{
		"Raven",
		"Ingrid",
		"Max",
		"Jenny",
		"Violet",
		"Aden"
	};

	constexpr std::array roarsAll{
		"*rattle*",
		"*uggghhh*",
		"*RRAAAUUUGGHHH*",
		"*GNNARRRR*",
		"*GRAWR*",
		"'hello there'"
	};

	Monster generate()
	{
		Monster::Type rndType{ static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types - 1)) };
		auto rndName{ namesAll[Random::get(0, namesAll.size() - 1)] };
		auto rndRoar{ roarsAll[Random::get(0, roarsAll.size() - 1)] };
		int rndHp{ Random::get(1, 100) };
		
		return {rndType, rndName, rndRoar, rndHp};
	}
}

void question3()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();
}