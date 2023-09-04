/*
	Что не так с этими фрагментами кода?
*/

// 2a)
// возврат висячей ссылки, т.к. массив локальный и будет уничтожен
// в конце функции
int& doSomething()
{
    int array[]{ 1, 2, 3, 4, 5 };
    return array[3];
}

// 2b)
// бесконечная рекурсия, т.к. отсутствуют условия завершения
int sumTo(int value)
{
    return value + sumTo(value - 1);
}

// 2с)
// возвращаемый тип не играет различающей роли при перегрузке
// функций, так что происходит нарушение ODR
float divide(float x, float y)
{
    return x / y;
}

double divide(float x, float y)
{
    return x / y;
}

// 2d)
// переполнение стека из-за создания слишком большого массива
#include <iostream>

int main()
{
    int array[100000000]{};

    for (auto x : array)
        std::cout << x << ' ';

    std::cout << '\n';

    return 0;
}

// 2е)
// необходима явная конвертация с-строки в инт,
// т.к. все аргументы командной строки передаются как char*
// (также argv[1] может не существовать)
#include <iostream>

int main(int argc, char* argv[])
{
    int age{ argv[1] };
    std::cout << "The user's age is " << age << '\n';

    return 0;
}