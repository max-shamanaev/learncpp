#include <array>
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <initializer_list>
#include <typeinfo>
#include <vector>
#include <string>
#include <string_view>

void quiz12_1();
void quiz12_8();
void q14_9();

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '%': return a % b;
	default:
		std::cout << "Error! Invalid operator was passed!\n";
		return 0;
	}
}

int sumTo(int value)
{
	int sum{ 0 };
	for (int i{ 1 }; i <= value; ++i)
		sum += i;

	return sum;
}

// a declaration for our function template (we don't need the definition any more)
template <typename T>
T max(T x, T y)
{
	return (x < y) ? y : x;
}

// Type/Struct members definition
struct Student {
	std::string name;
	int age;
};

// Function to find a student by name
// Takes a name and an array of Student objects
// Returns a pointer to the found student or nullptr if not found
const Student* findStudent(const std::string& name, const Student* students) {
	for (int i = 0; i < 3; ++i) {
		if (students[i].name == name) {
			return &students[i]; // Return address of a matching student, as each student got a different address.
		}
	}
	return nullptr; // No matching student found, return nullptr
}

void testFindStudent() {
	// Creating students using a vector
	std::vector<Student> students = {
			{"Alice", 20}, // [0]
			{"Bob", 22}, // [1]
			{"Charlie", 19} // [2]
	};

	// Call the findStudent function to search for a student named "Bob"
	// Pass the address of the first element in the vector using the data() function
	// Found student takes the return that is a pointer to the student struct, and the vector pass to get the information on vector for passing it to the function
	const Student* foundStudent = findStudent("s", students.data()); // const * can't change value.
	// foundStudent, as a pointer to Student*, gets the & of the matching student

	// Checking if a student was found (is not null)
	if (foundStudent != nullptr) { // foundStudent: 0xf73c48 (Bob)
		// Student found, print their name and age
		std::cout << "Student found: " << foundStudent->name << ", Age: " << foundStudent->age << '\n';
		// Doable as foundStudent is a * to Student, so it has access to their (public members)
	}
	else {
		// Student isn't found
		std::cout << "Student not found.\n";
	}
}

const int& getNextId()
{
	static int s_x{ 0 };
	++s_x;
	return s_x;
}

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};

std::string_view getAnimalName(Animal animal)
{
	using enum Animal;

	switch (animal)
	{
	case pig:		return "pig";
	case chicken:	return "chicken";
	case goat:		return "goat";
	case cat:		return "cat";
	case dog:		return "dog";
	case duck:		return "duck";
	default:		
		std::cout << "Error! Invalid animal.\n";
		return "";
	}
}

void printNumberOfLegs(Animal animal)
{
	using enum Animal;

	int legsNum{};
	switch (animal)
	{
	case chicken:
	case duck:
		legsNum = 2;
		break;
	case pig:
	case goat:
	case cat:
	case dog:
		legsNum = 4;
		break;
	default:
		std::cout << "Error! Uknown animal.\n";
		return;
	}

	std::cout << "A " << getAnimalName(animal) << " has " << legsNum << " legs.\n";
}

struct AdsRevenue
{
	int adsShown{};
	double adsClickedRate{};
	double avgAdRevenue{};
};

void printAdsInfo(const AdsRevenue& adsData)
{
	std::cout << "\nAmount of shown ads: " << adsData.adsShown << '\n';
	std::cout << "Percentage of clicked ads: " << adsData.adsClickedRate << '\n';
	std::cout << "Average revenue from one ad: " << adsData.avgAdRevenue << '\n';
	std::cout << "\nTotal for that day is: " 
		<< adsData.adsShown * adsData.adsClickedRate * adsData.avgAdRevenue << '\n';
}

/*
struct Fraction
{
	int numerator{};
	int denominator{ 1 }; // 1 to avoid division by zero
};

Fraction getFraction()
{
	Fraction fraction{};
	std::cout << "Enter a value for the numerator: ";
	std::cin >> fraction.numerator;
	std::cout << "Enter a value for the denominator: ";
	std::cin >> fraction.denominator;
	std::cout << '\n';

	return fraction;
}

Fraction multiplyFractions(const Fraction& x, const Fraction& y)
{
	return { x.numerator * y.numerator, x.denominator * y.denominator };
}

void printFraction(const Fraction& res)
{
	std::cout << res.numerator << "/" << res.denominator << '\n';
}
*/
template <typename T, typename U>
struct Pair
{
	T first{};
	U second{};
};

template <typename T, typename U>
void print(Pair<T, U> p)
{
	std::cout << '[' << p.first << ", " << p.second << ']';
}

template <typename T, typename U>
Pair(T, U)->Pair<T, U>;

int getInput()
{
	int num{};
	do
	{
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> num;

		if (std::cin.fail())
			std::cin.clear(); // reset any error flags

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
	} while (num < 1 || num > 9);

	return num;
}

void fizzbuzz(int max)
{
	int divisors[]{ 3, 5, 7, 11, 13, 17, 19 };
	std::string_view words[]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
	static_assert(std::size(divisors) == std::size(words) && "Length of the arrays are not equal!");

	for (int i{ 1 }; i <= max; ++i)
	{
		std::string str{ "" };
		for (int j{ 0 }; j < std::ssize(divisors); ++j)
		{
			if (i % divisors[j] == 0)
				str += words[j];
		}

		if (str != "")
			std::cout << str << '\n';
		else
			std::cout << i << '\n';
	}
}

void bubbleSort(int* arr, const int l)
{
	for (int i{ 0 }; i < l - 1; ++i)
	{
		bool isSwapped{ false };
		for (int j{ 0 }; j < l - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped)
		{
			std::cout << "Early termination on iteration " << i+1 << '\n';
			break;
		}
	}
}

int* findValue(int* start, int* end, int value)
{
	for (auto i{ start }; i != end; ++i)
	{
		if (*i == value)
			return i;
	}

	return end;
}

void q11_11()
{
	std::cout << "How many names would you like to enter? ";
	size_t namesNum{};
	std::cin >> namesNum;

	auto* names{ new std::string[namesNum] };
	for (size_t i{ 0 }; i < namesNum; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::getline(std::cin >> std::ws, names[i]);
	}

	std::sort(names, names + namesNum);

	std::cout << "\nHere is your sorted list:\n";
	for (size_t i = 0; i < namesNum; ++i)
	{
		std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
	}

	delete[] names;
}

// Our function will return true if the element matches
bool greater(int a, int b)
{
	// Order @a before @b if @a is greater than @b.
	return (a > b);
}

// sort accepts a comparison function
void sort(int* begin, int* end, std::function<bool(int, int)> compare = greater)
{
	for (auto startElement{ begin }; startElement != end - 1; ++startElement)
	{
		auto smallestElement{ startElement };

		for (auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
		{
			// the comparison function is used to check if the current element should be ordered
			// before the currently "smallest" element.
			if (compare(*currentElement, *smallestElement))
			{
				smallestElement = currentElement;
			}
		}

		std::swap(*startElement, *smallestElement);
	}
}

int factorial(int x)
{
	if (x == 0)
		return 1;

	return x * factorial(x - 1);
}

int sumDigits(int x)
{
	if (x / 10 == 0) // x < 10
		return x;

	return (x % 10) + sumDigits(x / 10);
}

void printBinary(unsigned int x)
{
	if (x / 2 > 0) // x > 1
		printBinary(x / 2);

	std::cout << x % 2;
}

class Stack
{
public:
	void reset()
	{
		m_size = 0;
	}

	bool push(int val)
	{
		if (m_size == m_stack.size())
			return false;
		else
		{
			m_stack[m_size++] = val;
			return true;
		}
	}

	int pop()
	{
		assert(!m_stack.empty() && "No elements to pop!");

		return m_stack[--m_size];
	}

	void print()
	{
		std::cout << "( ";

		for (size_t i{ 0 }; i < m_size; ++i)
			std::cout << m_stack[i] << ' ';

		std::cout << ")\n";
	}

private:
	size_t m_size{ 0 };
	std::array<int, 10> m_stack{};
};

class Ball
{
public:

	Ball(std::string_view color = "black", double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}

	Ball(double radius)
	{
		m_radius = radius;
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius " << m_radius << '\n';
	}

private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };
};

class RGBA
{
public:
	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255)
		: m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{

	}

	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red)
				  << " g=" << static_cast<int>(m_green)
				  << " b=" << static_cast<int>(m_blue)
				  << " a=" << static_cast<int>(m_alpha);
	}

private:
	std::uint8_t m_red	{ 0 };
	std::uint8_t m_green{ 0 };
	std::uint8_t m_blue	{ 0 };
	std::uint8_t m_alpha{ 255 };
};

class Vector3d;

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v);	
};

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector(const Vector3d& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

class MyString
{
public:
	MyString(std::string_view str)
		:m_str{ str }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& str)
	{
		out << str;
		return out;
	}

	std::string operator()(int startIndex, int count)
	{
		assert(startIndex >= 0 && startIndex < m_str.size() - 1);
		assert(count < m_str.size() - startIndex);

		return m_str.substr(startIndex, count);
	}

	std::string_view substr(int start, int count)
	{
		assert(start >= 0 && start < m_str.size() - 1);
		assert(count < m_str.size() - start);

		std::string_view sv{ m_str };
		return sv.substr(start, count);
	}

private:
	std::string m_str{};
};

class Teacher
{
private:
	std::string m_name{};

public:
	Teacher(std::string_view name)
		: m_name{ name }
	{
	}

	const std::string& getName() const { return m_name; }
};

class Department
{
private:
	std::vector<std::reference_wrapper<const Teacher>> m_teachers{}; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
	Department() = default;
	Department(const Teacher& teacher)
		: m_teachers{ teacher }
	{
	}

	void add(const Teacher& t)
	{
		m_teachers.push_back(t);
	}

	friend std::ostream& operator<<(std::ostream& out, const Department& dept)
	{
		out << "Department: ";
		for (const auto& teacher : dept.m_teachers)
			out << teacher.get().getName() << ' ';

		out << '\n';
		return out;
	}
};

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length)
		: m_length{ length }
		, m_data{ new int[static_cast<std::size_t>(length)] {} }
	{

	}

	IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
		: IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	IntArray(const IntArray&) = delete;
	IntArray& operator=(const IntArray&) = delete;

	~IntArray()
	{
		delete[] m_data;
	}

	IntArray& operator=(std::initializer_list<int> list)
	{
		int length = static_cast<int>(list.size());

		if (m_length != length)
		{
			m_length = length;
			delete[] m_data;
			m_data = (m_length != 0) ? new int[m_length] : nullptr;
		}

		for (size_t i{ 0 }; auto el : list)
		{
			m_data[i] = el;
			++i;
		}
		
		return *this;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }
};

class Fruit
{
public:
	Fruit(std::string_view name, std::string_view color)
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
	Apple(std::string_view name, std::string_view color, double fiber)
		: Fruit{ name, color }, m_fiber{ fiber }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Apple& a)
	{
		out << "Apple (" << a.getName() << ", " << a.getColor() << ", "
			<< a.m_fiber << ")";
		
		return out;
	}

private:
	double m_fiber{};
};

class Banana : public Fruit
{
public: 
	Banana(std::string_view name, std::string_view color)
		:  Fruit{name, color}
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Banana& b)
	{
		out << "Banana (" << b.getName() << ", " << b.getColor() << ")";

		return out;
	}
};

template <typename T>
class Storage
{
private:
	T m_value{};
public:
	Storage(T value)
		: m_value{ value }
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

int main()
{
	// Define some storage units
	Storage<int> nValue{ 5 };
	Storage<double> dValue{ 6.7 };

	// Print out some values
	nValue.print();
	dValue.print();
}