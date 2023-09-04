/*
	�����������, ��� �� ������ ����, � ������� ����� ����� ������� � ����� 3 ���� ���������: 
	����� �������� (health potion), ������ (torch) � ������ (arrow). �������� ������������ ��� 
	������������� ��������� ����� ��������� � ������ std::array ��� �������� ���������� ������ 
	������� ��������, ������� ����� ����� (������������� ������������ � �������� �������� �������). 
	����� ������ ������ � 2 ������� ��������, 5 �������� � 10 ��������. �������� ������� 
	countTotalItems(), ������� ���������� ����� ���������� ���������, ������� ���� � ������. 
	��������� ���� ������� main() ����������� �������� �������� countTotalItems(), � ����� ���������� �������.
*/

#include <array>
#include <iostream>
#include <numeric>

namespace items
{
	enum ItemType
	{
		hp_potion,
		torch,
		arrow,
		types_total,
	};
}

int countTotalItems(std::array<int, items::types_total>& items)
{
	return std::reduce(items.begin(), items.end());
}

void question1()
{
	std::array<int, items::types_total> playerInventory{ 2, 5, 10 };
	
	std::cout << "Items total: " << countTotalItems(playerInventory) << '\n';
	std::cout << "Torches: " << playerInventory[items::torch] << '\n';
}