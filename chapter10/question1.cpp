/*
	При разработке игры мы решаем, что нам нужны монстры, ведь всем нравится сражаться с монстрами. 
	Объявите структуру, представляющую вашего монстра. 
	Монстр должен иметь один из следующих типов: огр, дракон, орк, гигантский паук или слизь. Используйте для этого класс перечисления.

	У каждого отдельного монстра также должно быть имя (используйте std::string), 
	а также количество здоровья, которое показывает, сколько урона он может получить до своей смерти. 
	Напишите функцию с именем printMonster(), которая выводит на печать все члены структуры. 
	Создайте экземпляр огра и слизи, инициализируйте их с помощью списка инициализаторов и передайте их в printMonster().

	Ваша программа должна выдать следующий результат:

	This Ogre is named Torg and has 145 health.
	This Slime is named Blurp and has 23 health.
*/

#include <string>
#include <iostream>

// 2ой способ - вложенный в структуру enum 
// и вместо перегрузки << - string_view toString(MonsterType)

enum class MonsterType
{
	none,
	ogre,
	dragon,
	orc,
	giant_spider,
	slime
};

std::ostream& operator<<(std::ostream& out, MonsterType type)
{
	switch (type)
	{
	case MonsterType::ogre:
		out << "Ogre";
		break;
	case MonsterType::dragon:
		out << "Dragon";
		break;
	case MonsterType::orc:
		out << "Orc";
		break;
	case MonsterType::giant_spider:
		out << "Giant spider";
		break;
	case MonsterType::slime:
		out << "Slime";
		break;
	default:
		out << "UKNOWN MONSTER TYPE";
		break;
	}
	return out;
}

struct Monster
{
	MonsterType type{};
	std::string name{};
	double hp{};
};

void printMonster(const Monster& monster)
{
	std::cout << "This " << monster.type << " is named " << monster.name
		<< " and has " << monster.hp << " health.\n";
}

void question1()
{
	Monster ogre{ MonsterType::ogre, "Torg", 145 };
	Monster slime{ MonsterType::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);
}