#include <iostream>
using namespace std;
#define max_size 10
int main(void)
{
    int a[max_size][max_size];
    int b[max_size][max_size];
    int c[max_size][max_size] = {0};
    // int i,j,k;
    int RowA, ColA, ColB;
    cout << "输入A的行数、列数和B的列数\n";
    cin >> RowA >> ColA >> ColB;
    for (int i = 0; i < RowA; i++)
    {
        for (int j = 0; j < ColA; j++)
        {
            cout << "输入a" << i << j << endl;
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < ColA; i++)
    {
        for (int j = 0; j < ColB; j++)
        {
            cout << "输入b" << i << j << endl;
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < RowA; i++)
    {
        for (int j = 0; j < ColB; j++)
        {
            for (int k = 0; k < ColA; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
        for (int i = 0; i < RowA; i++)
    {
        for (int j = 0; j < ColB; j++)
        {
            cout << c[i][j] << " ";
        }
    }

    return 0;
}