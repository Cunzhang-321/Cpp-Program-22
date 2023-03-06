#include <iostream>
using namespace std;
int main()
{
    int n, x;
    int tem;      // 最终输出
    int flag = 0;int flag2=0; // 1在数组中
    int m[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (x == m[i])
        {
            tem = i;
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        for(int i=0;i<n;i++)
        {if(x<m[i]) {tem=i;flag2=1;break;}}
        if(!flag2) tem=n;
    }
    cout<<tem;
    return 0;
}