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
    cout << "������һ�������ĸ���:";
    cin >> m;
    cout << "������һ��ʵ���ĸ���:";
    cin >> n;
    cout << "������һ��������";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << "������һ��ʵ����";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << "��������Сֵ��" << Min(a, m) << endl;
    cout << "ʵ������Сֵ��" << Min(b, n);
    return 0;
}
