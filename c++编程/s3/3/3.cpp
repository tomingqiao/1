#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int h, l;
    cout << "������ͼ�ε�������";
    cin >> h;
    cout << "������ͼ�ε�������";
    cin >> l;
    for (int i = 0; i < h; i++)
    {
        for (int a = 0; a < i; a++)
        {
            cout << " ";
        }

        for (int i = 0; i < l; i++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}
