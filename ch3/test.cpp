#include <iostream>
using namespace std;
void f(int a, int &b)
{
    static int c=3;
    c+=a*2+3;
    b=a++;
}

int main()
{
    int a[10]={3,15,9,8,12,35};
    int b[40]={0};
    for(int i=0;i<3;i++)
    {
        f(a[i],b[i]);
        b[i]++;
        cout<<b[i]<<endl;
    }
}