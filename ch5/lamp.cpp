#include<iostream>
using namespace std;
int main()
{
    int n,k,i,j;
    cin>>n>>k;
    int a[n]={0};
    for(i=0;i<n;i++){

        for(j=1;j<=k;j++){
            if((i+1)%j==0) a[i]++;
        }
          if(a[i]%2==1) cout<<i+1<<" ";
    }
    return 0;
}