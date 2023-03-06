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
int trans(int a,int b,int c)
{
    int result=0;
    result=pow(a,3)+pow(b,3)+c;
    return result;
}
int main()
{
    int i=0;
    int m;
    cin>>m;
    int temp=m;
    int s[10]={0};
    while(temp){
        s[i]=temp%10;
        temp/=10;
        i++;

    }

    return 0;
}