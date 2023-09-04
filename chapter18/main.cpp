#include <iostream>
#include <vector>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& s)
    {
        return s.print(out);
    }
};

class Point
{
public:
    Point() = default;

    Point(int x, int y)
        : m_x{ x }, m_y{ y }
    {

    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.m_x << ", " << p.m_y << ')';
    }

private:
    int m_x{};
    int m_y{};
};

class Triangle : public Shape
{
public:
    Triangle(Point a, Point b, Point c)
        : m_a{ a }, m_b{ b }, m_c{ c }
    {

    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ')';
        return out;
    }

private:
    Point m_a{};
    Point m_b{};
    Point m_c{};
};

class Circle : public Shape
{
public:
    Circle(Point center, int radius)
        : m_radius{ radius }, m_center{ center }
    {

    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", radius " << m_radius << ')';
        return out;
    }

    int getRadius() const
    {
        return m_radius;
    }

private:
    Point m_center{};
    int m_radius{};
};

int getLargestRadius(const std::vector<Shape*>& shapes)
{
    int maxRadius{ 0 };
    for (const auto* shape : shapes)
    {
        auto* circle{ dynamic_cast<const Circle*>(shape) };

        if (circle && circle->getRadius() > maxRadius)
            maxRadius = circle->getRadius();
    }

    return maxRadius;
}

int main()
{
    std::vector<Shape*> v{
      new Circle{Point{ 1, 2 }, 7},
      new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
      new Circle{Point{ 7, 8 }, 3}
    };

    // print each shape in vector v on its own line here
    for (const auto* el : v)
    {
        std::cout << *el << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for (const auto* el : v)
    {
        delete el;
    }

    return 0;
}