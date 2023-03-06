#include<iostream>
using namespace std;

int fib()
{
    static int a=1;
    static int b=0;
    int c;
    c=b;b=a;a=a+c;
    return b;
}
int main()
{
    int n;
    cin>>n;
    while(n)
    {
        cout<<fib()<<endl;
        n--;
    }
    return 0;
}