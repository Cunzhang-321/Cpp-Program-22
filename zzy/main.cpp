#include <iostream>
using namespace std;
int main()
{
    int a,b,hun,ten,one;
    hun=ten=one=0;
    int x=0;
    cin>>a>>b;
    for(int i=a; i<=b; i++)
    {
        one=i%10;
        hun=i/100;
        ten=(i-hun)/10;
        if(i==(one*one*one+ten*ten*ten+hun*hun*hun))
        {
            x=i;
            cout<<i<<" ";
        }else continue;

    }
    if(x==0) cout<<"no"<<endl;
    return 0;
}
