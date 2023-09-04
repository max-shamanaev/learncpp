/*
	a) Напишите классы Apple и Banana, производные от общего класса Fruit.
	У Fruit должно быть два члена: название и цвет.
	b) Добавьте в предыдущую программу новый класс GrannySmith (такой 
	сорт яблок), унаследованный от Apple.
*/

#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
public:
	Fruit(std::string_view name = "", std::string_view color = "")
		: m_name{ name }, m_color{ color }
	{

	}

	std::string_view getName() const { return m_name; }
	std::string_view getColor() const { return m_color; }

private:
	std::string m_name{};
	std::string m_color{};
};

class Apple : public Fruit
{
public:
	Apple(std::string_view color = "red")
		: Fruit{ "apple", color }
	{

	}

	//Дополнение:
	/*protected:*/
	Apple(const std::string& cultivar, std::string_view color)
		: Fruit{ cultivar + " apple", color }
	{

	}
};

class GrannySmith : public Apple
{
public:
	GrannySmith()
		: Apple{ "granny smith" , "green" }
	{

	}
};

class Banana : public Fruit
{
public:
	Banana()
		: Fruit{ "banana", "yellow" }
	{

	}
};

void question2()
{
	Apple a{ "red" };
	Banana b{};

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

	std::cout << '\n';

	Apple a2{ "red" };
	Banana b2;
	GrannySmith c;

	std::cout << "My " << a2.getName() << " is " << a2.getColor() << ".\n";
	std::cout << "My " << b2.getName() << " is " << b2.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}