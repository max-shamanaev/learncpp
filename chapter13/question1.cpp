/*
    a) Напишите класс с именем Point2d. Point2d должен содержать две переменные-члены типа 
    double: m_x и m_y, обе по умолчанию равны 0.0. Предоставьте конструктор и функцию печати.

    b) Теперь добавьте функцию-член с именем distanceTo, которая принимает другой объект 
    Point2d в качестве параметра и вычисляет расстояние между ними. Для двух точек (x1, y1) 
    и (x2, y2) расстояние между ними можно рассчитать как std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)).

    c) Измените функцию distanceTo с функции-члена на функцию, не являющуюся членом, которая принимает 
    в качестве параметров два объекта Point. Также переименуйте ее в distanceFrom.
*/

#include <cmath>
#include <iostream>

class Point2d
{
public:
    friend double distanceFrom(const Point2d& p1, const Point2d& p2);

    Point2d() = default;

    Point2d(double x, double y)
        : m_x{ x }, m_y{ y }
    {

    }

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };
};

double distanceFrom(const Point2d& p1, const Point2d& p2)
{
    return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}

void question1()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}