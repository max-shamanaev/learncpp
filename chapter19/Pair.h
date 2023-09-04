#pragma once

template<typename T, typename S>
class Pair
{
public:
	Pair(const T& first, const S& second)
		: m_first{ first }, m_second{ second }
	{

	}

	T& first() { return m_first; }
	S& second() { return m_second; }
	const T& first() const { return m_first; }
	const S& second() const { return m_second; }

private:
	T m_first{};
	S m_second{};
};