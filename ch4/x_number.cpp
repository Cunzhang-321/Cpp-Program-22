#include <iostream>
using namespace std;
int main()
{
    int a,b,temp,x;
    cin>>a>>b;
 
    int found=0;

    for(int i=a;i<=b;i++){
        temp=i;
        x=0;
        while (temp!=0)
        {
            int digi=temp%10;
            x+=digi*digi*digi;
            temp/=10;
        }
        if(x==i) {cout<<i<<" ";
        found=1;}
    }
    if (!found) cout<<"no"<<endl;
    return 0;
}
