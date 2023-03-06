#include <iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int sum0=0;
int x;
int sum1=n*(n+1)/2;
for(int i=0;i<n;i++){
    cin>>x;
    sum0=sum0+x;
}
cout<<sum1-sum0;
    return 0;
}
