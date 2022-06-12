#include <iostream>
using namespace std;
int Min(int a[], int m)
{
    int min = 10000;
    for (int i = 0; i < m; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
double Min(double a[], int n)
{
    double min = 10000;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
int main(int argc, char const *argv[])
{
    int a[5], m, n;
    double b[5];
    cout << "请输入一组整数的个数:";
    cin >> m;
    cout << "请输入一组实数的个数:";
    cin >> n;
    cout << "请输入一组整数：";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << "请输入一组实数：";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << "整数中最小值：" << Min(a, m) << endl;
    cout << "实数中最小值：" << Min(b, n);
    return 0;
}
