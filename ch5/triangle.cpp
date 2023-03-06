#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int R, i, j;
    cin >> R;
    int a[102][102];
    int f[102][102] = {0};
    for (i = 1; i <= R; i++)
    {
        for (j = 1; j <= i; j++)
            cin >> a[i][j];
    }
    f[1][1] = a[1][1];
    for (i = 1; i < R; i++)
    {
        for (j = 1; j <= i; j++)
            if (f[i][j - 1] > f[i][j])
                f[i + 1][j] = f[i][j - 1] + a[i + 1][j];
            else
                f[i + 1][j] = f[i][j] + a[i + 1][j];
    }
    int res = 0;
    for (i = 1; i <= R; i++)
        res = max(res, f[R][i]);
    cout << res;
    return 0;
}