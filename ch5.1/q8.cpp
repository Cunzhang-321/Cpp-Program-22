#include <iostream>
using namespace std;

int main()
{
    int n, x;int j;int i;
    int flag = 0; // 0为没有
    int s[100];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> s[i];
    cin >> x;
    for (j=0;j<n;j++)
    {
        if(x==s[j])
        {
            flag=1;
            break;
        }
    }
    int counter=j+1;
    for(i=j+1;i<n;i++)
    if(x==s[i])
    {
        flag=2;counter=i;
    }
    if(flag==0) cout<<"-1 -1";
    if(flag==1) cout<<j<<" "<<j;
    if(flag==2) cout<<j<<" "<<counter;
        return 0;
}