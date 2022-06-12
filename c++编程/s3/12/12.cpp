#include <iostream>
using namespace std;
class Shape
{
private:
public:
    Shape(/* args */);
    ~Shape();
    virtual void area() = 0;
};

Shape::Shape(/* args */)
{
}

Shape::~Shape()
{
}
class Circle : Shape
{
private:
    float r, s;

public:
    Circle(float m);
    ~Circle();
    void area();
};
void Circle::area()
{
    s = 3.14 * r * r;
    cout << "Բ�뾶��" << r << "     Բ�����" << s << endl;
}
Circle::Circle(float m)
{
    r = m;
}

Circle::~Circle()
{
}
class Triangle : Shape
{
private:
    float w, h, s;

public:
    Triangle(float m, float n);
    ~Triangle();
    void area();
};
void Triangle::area()
{
    s = w * h / 2;
    cout << "�����εױߣ�" << w << "     �����θߣ�" << h << "     �����������" << s;
}
Triangle::Triangle(float m, float n)
{
    w = m;
    h = n;
}

Triangle::~Triangle()
{
}
int main(int argc, char const *argv[])
{
    Circle c(5);
    Triangle t(3, 4);
    c.area();
    t.area();
    return 0;
}
