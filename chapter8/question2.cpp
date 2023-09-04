/*

2a) ќбновите следующую программу, использу€ псевдонимы типов
2b) ќсновыва€сь на вопросе 2a, объ€сните, 
    почему следующа€ инструкци€ будет или не будет компилироватьс€: radians = degrees;
    
    ќтвет: будет компилироватьс€, т.к. данной инструкцией производитс€ обычное присваивание значени€
    переменной degrees переменной radians, где у обоих переменных тип double
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