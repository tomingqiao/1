using namespace std;
#include <iostream>
class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(/* args */);
    Date(int y, int m, int d);
    ~Date();
    void print();
};
Date::Date(/* args */)
{
    year = 1;
    month = 1;
    day = 1;
}
Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
void Date::print()
{
    cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ";
}
Date::~Date()
{
}
int main(int argc, char const *argv[])
{
    Date date(1949, 10, 1);
    date.print();
    return 0;
}
