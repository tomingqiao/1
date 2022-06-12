#include <iostream>
using namespace std;
class Square
{
private:
    float r, p, s;

public:
    Square(float d);
    ~Square();
    void perimeter();
    void area();
    void print();
};

Square::Square(float d = 0)
{
    r = d;
}
void Square::perimeter()
{
    p = 4 * r;
}
void Square::area()
{
    s = r * r;
}
void Square::print()
{
    cout << "边长：" << r << endl
         << "周长：" << p << endl
         << "面积：" << s;
}
Square::~Square()
{
}
int main(int argc, char const *argv[])
{
    Square a(4.0);
    a.perimeter();
    a.area();
    a.print();
    return 0;
}
