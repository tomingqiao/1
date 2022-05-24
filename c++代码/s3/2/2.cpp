#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    double c, k;
    cout << "请输入长方形的长：";
    cin >> c;
    cout << "请输入长方形的宽：";
    cin >> k;
    cout << "长方形的周长:" << c * 2 + k * 2 << endl;
    cout << "长方形的面积:" << c * k;
    return 0;
}
