#include<iostream>
using namespace std;
int main()
{
    int a,b; //a十进制 b进制
    int counter=0;
    int x[10];
    cin>>a>>b;
    int temp=a;
    while(temp)
    {
        x[counter]=temp%b;
        temp/=b;
        counter++;
    }
    for(int i=counter-1;i>=0;i--)
    cout<<x[i];
    return 0;
}