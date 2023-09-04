/*
    � ������ ����
    �) �������� ����������� ������ ������� binarySearch.
    �) �������� ����������� ������ ������� binarySearch.
*/

#include <iostream>
#include <iterator>

// array - ��� ������ ��� ������.
// target - ��� ��������, ������� �� �������� ����������, ���� ��� ��� ���.
// min - ��� ������ ������ ������� �������, � ������� �� ����.
// max - ��� ������ ������� ������� �������, � ������� �� ����.
// binarySearch() ������ ���������� ������ �������� ��������, ���� target ������, ����� -1
int binarySearch(const int* array, int target, int min, int max)
{
    // ����������: ������ ������ ������������
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
        // ����������: ��� ��������� ������������
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

    // �� ���������� �������������� ����� ��������, ����� �������,
    // ���� �� ��� ��������� ����������
    constexpr int numTestValues{ 9 };
    // ��� �������� ��������
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // � ��� ��������� ���������� ��� ������� ��������
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // ���������� ��� �������� ��������
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // �������, ���� �� ���� �������� �������� � �������
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // ���� ��������� ������������� ����������, ����� �������!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // ����� ���� ������� binarySearch() �� ��������
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}