#include <iostream>
using namespace std;

int main()
{
    int i,k,n,x;
    int IsDelete=0;
    n=0;k=0;
    int a[1000];int b[1000];
    while(cin>>x)
    {
        a[n]=x;
        n++;
    }
    b[0]=a[0];
    for(i=1;i<n;i++){
        IsDelete=0;
        for(int t=0;t<=k;)
        {
            if(a[i]==b[t]) {IsDelete=1;break;}
            else ++t;
        }
    if(!IsDelete) b[++k]=a[i];
    }

for(int t=0; t<=k; t++) cout<<b[t]<<" ";

    return 0;
}