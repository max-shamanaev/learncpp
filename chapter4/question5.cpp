#include <cstdint>
#include <iostream>

void question5()
{
    std::cout << "How old are you?\n";

    /*
        1. ������ ��� ����� ���� ��� unsigned char 
        => ����� ����� �������� �����������

        std::uint8_t age{};
    */ 
    int age{};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    // (�� �����) 2. 16 - ���������� ����� (����� constexpr)
    // (�� �����) 3. ������������� ������� ������� ��� ���������� �������
    if (age >= 16)
        std::cout << "x";
    else
        std::cout << " ";

    std::cout << "]\n";
}