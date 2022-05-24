#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int h, l;
    cout << "请输入图形的行数：";
    cin >> h;
    cout << "请输入图形的列数：";
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
