/*
	��� ���������� ���� �� ������, ��� ��� ����� �������, ���� ���� �������� ��������� � ���������. 
	�������� ���������, �������������� ������ �������. 
	������ ������ ����� ���� �� ��������� �����: ���, ������, ���, ���������� ���� ��� �����. ����������� ��� ����� ����� ������������.

	� ������� ���������� ������� ����� ������ ���� ��� (����������� std::string), 
	� ����� ���������� ��������, ������� ����������, ������� ����� �� ����� �������� �� ����� ������. 
	�������� ������� � ������ printMonster(), ������� ������� �� ������ ��� ����� ���������. 
	�������� ��������� ���� � �����, ��������������� �� � ������� ������ ��������������� � ��������� �� � printMonster().

	���� ��������� ������ ������ ��������� ���������:

	This Ogre is named Torg and has 145 health.
	This Slime is named Blurp and has 23 health.
*/

#include <string>
#include <iostream>

// 2�� ������ - ��������� � ��������� enum 
// � ������ ���������� << - string_view toString(MonsterType)

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