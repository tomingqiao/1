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
    cout << "�����г���ƽ��ֵ�����ݸ�����" << count(a, m) << endl;
    cout << "ʵ���г���ƽ��ֵ�����ݸ�����" << count(b, n);
    return 0;
}
