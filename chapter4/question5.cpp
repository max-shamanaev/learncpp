#include <cstdint>
#include <iostream>

void question5()
{
    std::cout << "How old are you?\n";

    /*
        1. Данный тип ведет себя как unsigned char 
        => число будет записано некорректно

        std::uint8_t age{};
    */ 
    int age{};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    // (не нашел) 2. 16 - магическое число (лучше constexpr)
    // (не нашел) 3. Использование двойных кавычек для одинарного символа
    if (age >= 16)
        std::cout << "x";
    else
        std::cout << " ";

    std::cout << "]\n";
}