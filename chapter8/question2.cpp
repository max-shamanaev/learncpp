/*

2a) �������� ��������� ���������, ��������� ���������� �����
2b) ����������� �� ������� 2a, ���������, 
    ������ ��������� ���������� ����� ��� �� ����� ���������������: radians = degrees;
    
    �����: ����� ���������������, �.�. ������ ����������� ������������ ������� ������������ ��������
    ���������� degrees ���������� radians, ��� � ����� ���������� ��� double
*/

#include <iostream>

namespace constants
{
    inline constexpr double pi{ 3.14159 };
}

using Radians = double;
using Degrees = double;
Radians convertToRadians(Degrees degrees)
{
    return degrees * constants::pi / 180;
}

void question2()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians{ convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

}