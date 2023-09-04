#include <iostream>

class Base
{
protected:
	~Base() // note: not virtual
	{
		std::cout << "Calling ~Base()\n";
	}
};

class Derived : public Base
{
private:
	int* m_array{};

public:
	Derived(int length)
		: m_array{ new int[length] }
	{
	}

	~Derived() // note: not virtual
	{
		std::cout << "Calling ~Derived()\n";
		delete[] m_array;
	}
};

int main()
{
	Derived* derived{ new Derived(5) };
	Base* base{ derived };

	//delete base;
	//delete derived;

	Base bOnStack{};

	return 0;
}