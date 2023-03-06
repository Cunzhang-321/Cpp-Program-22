#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int i,j,temp,n;
    char a[80];
    cin.getline(a,80);
    n=strlen(a);
        for (i = 0; i < n; ++i)
        for (j = i + 1; j < n;)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < n - 1; ++k)
                    a[k] = a[k + 1];

                --n;
            }
            else
                ++j;
        }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i=0;i<n;i++) cout<<a[i];
    return 0;
}