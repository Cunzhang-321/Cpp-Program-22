#include <iostream>
using namespace std;
int main()
{
    int s[100];
    int n;
    cin >> n;
    for (int m = 0; m < n; m++)
        cin >> s[m];
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
            if (s[j] > s[i])
            {
                temp = s[i];
                for (int m = i; m > j; m--)
                {
                    s[m] = s[m - 1];
                }
                s[j] = temp;
            }
    }
    for (int m = 0; m < n; m++)
        cout << s[m] << " ";
    return 0;
}