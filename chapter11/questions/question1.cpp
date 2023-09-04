/*
	Представьте, что вы пишете игру, в которой игрок может держать в руках 3 типа предметов: 
	зелья здоровья (health potion), факелы (torch) и стрелы (arrow). Создайте перечисление для 
	идентификации различных типов элементов и массив std::array для хранения количества единиц 
	каждого элемента, который несет игрок (перечислители используются в качестве индексов массива). 
	Игрок должен начать с 2 зельями здоровья, 5 факелами и 10 стрелами. Напишите функцию 
	countTotalItems(), которая возвращает общее количество элементов, которые есть у игрока. 
	Заставьте вашу функцию main() распечатать выходное значение countTotalItems(), а также количество факелов.
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