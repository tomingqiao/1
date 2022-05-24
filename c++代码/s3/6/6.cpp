#include <iostream>
using namespace std;
int count(int a[], int m)
{
    int pj = 0, g = 0;
    for (int i = 0; i < m; i++)
    {
        pj = pj + a[i];
    }
    pj = pj / m;
    for (int i = 0; i < m; i++)
    {
        if (a[i] > pj)
        {
            g++;
        }
    }
    return g;
}
double count(double a[], int n)
{
    double pj = 0, g = 0;
    for (int i = 0; i < n; i++)
    {
        pj = pj + a[i];
    }
    pj = pj / n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > pj)
        {
            g++;
        }
    }
    return g;
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
    cout << "整数中超过平均值的数据个数：" << count(a, m) << endl;
    cout << "实数中超过平均值的数据个数：" << count(b, n);
    return 0;
}
