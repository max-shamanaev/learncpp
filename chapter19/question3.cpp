/*
	Пара строка-значение – это особый тип пары, где первое значение всегда является 
	строковым типом, а второе значение может быть любого типа. Напишите шаблон класса
	с именем StringValuePair, который наследуется от частично специализированного 
	класса Pair (использующего std::string в качестве первого типа и позволяющего 
	пользователю указать второй тип).
*/

#include "Pair.h"

#include <iostream>
#include <string>

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& str, const T& val)
		: Pair<std::string, T>{ str, val }
	{

	}
};

void question3()
{
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}