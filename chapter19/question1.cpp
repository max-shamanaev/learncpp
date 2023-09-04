/*
	Ќапишите шаблон класса с именем Pair1, который позвол€ет пользователю
	определ€ть один шаблонный тип, который используетс€ дл€ обоих значений
	в паре.
*/

#include <iostream>

template<typename T>
class Pair1
{
public:
	//ƒополнение: const &
	Pair1(const T& first, const T& second)
		: m_first{ first }, m_second{ second }
	{

	}

	//ƒополнение: дл€ не-конст объектов
	T& first() { return m_first; }
	T& second() { return m_second; }

	const T& first() const { return m_first; }
	const T& second() const { return m_second; }

private:
	T m_first{};
	T m_second{};
};

void question1()
{
	Pair1<int> p1{ 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2{ 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}