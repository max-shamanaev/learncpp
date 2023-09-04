/*
	Напишите свой собственный класс целочисленного массива с именем IntArray с нуля
	(не используйте std::array или std::vector). Пользователи должны передавать размер 
	массива при его создании, и массив должен размещаться динамически. Используйте 
	инструкции assert для защиты от недопустимых данных. Создайте любые конструкторы и 
	перегруженные операторы, необходимые для правильной работы следующей программы

	Выход:
	5 8 2 3 6
	5 8 2 3 6
*/

#include <cassert>
#include <iostream>
#include <utility>

class IntArray
{
public:
	IntArray() = default;
	IntArray(size_t size);
	IntArray(const IntArray& other);
	~IntArray();

	IntArray& operator=(IntArray other);
	int& operator[](size_t index);
	int operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);
	friend void swap(IntArray& arr1, IntArray& arr2);

private:
	size_t m_size{ 0 };
	int*   m_array{ nullptr };
};

IntArray::IntArray(size_t size)
	: m_size{ size }
{
	if (m_size != 0)
		m_array = new int[size]/*{}*/; // Дополнение: value initialization
	else
		m_array = nullptr;
}

IntArray::IntArray(const IntArray& other)
	: m_size{ other.m_size }
{
	delete[] m_array;
	m_array = nullptr;

	if (other.m_array && m_size != 0)
	{
		m_array = new int[m_size];
		for (size_t i{ 0 }; i < m_size; ++i)
			m_array[i] = other.m_array[i];
	}
}

IntArray::~IntArray()
{
	delete[] m_array;
	m_array = nullptr;
}

// Реализация copy-and-swap
IntArray& IntArray::operator=(IntArray other)
{
	swap(*this, other);
	return *this;
}

int& IntArray::operator[](size_t index)
{
	assert(index < m_size && "Index out of range!");
	return m_array[index];
}

int IntArray::operator[](size_t index) const
{
	assert(index < m_size && "Index out of range!");
	return m_array[index];
}

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
	for (size_t i{ 0 }; i < arr.m_size; ++i)
		out << arr[i] << ' ';
	
	return out;
}

void swap(IntArray& arr1, IntArray& arr2)
{
	std::swap(arr1.m_size, arr2.m_size);
	std::swap(arr1.m_array, arr2.m_array);
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

void question3()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;
	
	a[4] = 7;

	std::cout << b << '\n';
}