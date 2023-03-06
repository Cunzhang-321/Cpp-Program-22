#include <iostream>
using namespace std;

int main()
{
    int n;
    int mat[20][20];
    int j;
    int max = 1;
    int line = 0;
    int counter;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                break;
            }
            else
                counter = j;
        }
        if (counter == n)
        {
            line = i;
            break;
        }
        if (counter > max)
        {
            max = counter;
            line = i;
        }
    }
    cout << line;

    return 0;
}