/*
    ¬ данном коде
    а) Ќапишите итеративную версию функции binarySearch.
    б) Ќапишите рекурсивную версию функции binarySearch.
*/

#include <iostream>
#include <iterator>

// array - это массив дл€ поиска.
// target - это значение, которое мы пытаемс€ определить, есть оно или нет.
// min - это индекс нижней границы массива, в котором мы ищем.
// max - это индекс верхней границы массива, в котором мы ищем.
// binarySearch() должна возвращать индекс целевого элемента, если target найден, иначе -1
int binarySearch(const int* array, int target, int min, int max)
{
    // ƒополнение: массив должен существовать
    // assert(array);

#define RECURSIVE 0
#if RECURSIVE
    
    if (min > max)
        return -1;

    int searchIndex{ (min + max) / 2 };

    if (target == array[searchIndex])
        return searchIndex;
    
    if (target < array[searchIndex])
        binarySearch(array, target, min, searchIndex - 1);
    else
        binarySearch(array, target, searchIndex + 1, max);

#else

    while (min <= max)
    {
        // ƒополнение: дл€ избежание переполнени€
        // int searchIndex{ std::midpoint(min, max) }; // C++20
        // int midpoint{ min + ((max-min) / 2) };

        int searchIndex{ (min + max) / 2 };

        if (target == array[searchIndex])
            return searchIndex;

        if (target < array[searchIndex])
            max = searchIndex - 1;
        else
            min = searchIndex + 1;
    }

    return -1;

#endif
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // ћы собираемс€ протестировать набор значений, чтобы увидеть,
    // дают ли они ожидаемые результаты
    constexpr int numTestValues{ 9 };
    // ¬от тестовые значени€
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // ј вот ожидаемые результаты дл€ каждого значени€
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // ѕеребираем все тестовые значени€
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // —мотрим, есть ли наше тестовое значение в массиве
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // ≈сли результат соответствует ожидаемому, тогда отлично!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // иначе наша функци€ binarySearch() не работает
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}