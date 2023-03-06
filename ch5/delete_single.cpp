#include <iostream>
using namespace std;

int main()
{

    int i, k, n, x, j;
    n = 0;
    k = 0;
    int a[1000];
    while (cin >> x)
    {
        a[n] = x;
        n++;
    }
    for (i = 0; i < n; ++i)
        for (j = i + 1; j < n;)
        {
            if (a[i] == a[j])
            {
                for (k = j; k < n - 1; ++k)
                    a[k] = a[k + 1];

                --n;
            }
            else
                ++j;
        }

    cout << n << " ";
    for (i = 0; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}