#include<iostream>
using namespace std;
int main(){
    double sum=0.00;int n,k;
    cin>>k;
    for(int n=1;sum<=k;n+=1)
    {sum=sum+1/n;}
    cout<<n<<endl;
    return 0;
}