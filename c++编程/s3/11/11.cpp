#include <iostream>
using namespace std;
class Shape
{
protected:
    int length, breadth;

public:
    Shape(int x, int y);
    ~Shape();
    virtual void area() = 0;
};
Shape::Shape(int x, int y)
{
    length = x;
    breadth = y;
}
Shape::~Shape()
{
}
class Rectangle : Shape
{
private:
    /* data */
public:
    Rectangle(int x, int y);
    ~Rectangle();
    void area();
};
Rectangle::Rectangle(int x, int y) : Shape(x, y)
{
    length = x;
    breadth = y;
}
void Rectangle::area()
{
    int m;
    m = length * breadth;
    cout << "Rectangle:" << endl
         << "    length:" << length << endl
         << "    breadth:" << breadth << endl
         << "    area:" << m;
}
Rectangle::~Rectangle()
{
}
int main(int argc, char const *argv[])
{
    Rectangle r(3, 5);
    r.area();
    return 0;
}
