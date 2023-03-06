#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    long i;
    i = a+b;

if((i^a)<0 && (i^b)<0)

    cout<<"error";
    else
cout<<a+b<<endl;
    return 0;
}