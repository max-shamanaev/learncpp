/*
	��� �� ��� � ����� ����������� ����?
*/

// 2a)
// ������� ������� ������, �.�. ������ ��������� � ����� ���������
// � ����� �������
int& doSomething()
{
    int array[]{ 1, 2, 3, 4, 5 };
    return array[3];
}

// 2b)
// ����������� ��������, �.�. ����������� ������� ����������
int sumTo(int value)
{
    return value + sumTo(value - 1);
}

// 2�)
// ������������ ��� �� ������ ����������� ���� ��� ����������
// �������, ��� ��� ���������� ��������� ODR
float divide(float x, float y)
{
    return x / y;
}

double divide(float x, float y)
{
    return x / y;
}

// 2d)
// ������������ ����� ��-�� �������� ������� �������� �������
#include <iostream>

int main()
{
    int array[100000000]{};

    for (auto x : array)
        std::cout << x << ' ';

    std::cout << '\n';

    return 0;
}

// 2�)
// ���������� ����� ����������� �-������ � ���,
// �.�. ��� ��������� ��������� ������ ���������� ��� char*
// (����� argv[1] ����� �� ������������)
#include <iostream>

int main(int argc, char* argv[])
{
    int age{ argv[1] };
    std::cout << "The user's age is " << age << '\n';

    return 0;
}