#include <iostream>
using namespace std;
int pow(int a, int x)
{
    int result = 1;
    for (int m = 0; m < x; m++)
    {
        result *= a;
    }
    return result;
}
int transfer(char arr[], int i)
{   int result2=0;
    for (int k = 0; k < i; k++)
    {
        result2+=pow(10,i-k-1)*(int(arr[k])-48);
    }
    return result2;
}
int main()
{
    char ch[80]="";
    char num[80]="";
    int i = 0;
    int j = 0;
    cin.getline(ch, 80);
    while (ch[i])
    {
        if (ch[i] >= '0' && ch[i] <= '9')
        {
            num[j++] = ch[i];
            i++;
        }
        else
            i++;
    }
int res;
res=transfer(num,j);
cout<<res*2;
    return 0;
}