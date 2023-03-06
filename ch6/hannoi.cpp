#include<iostream>
using namespace std;
int movecount = 0;
int abc_count[3] = {0,0,0};  //三个盘子计数器
void hannoi(int n,int a,int b,int c)   //定义与实现子函数
{
    //static int movecount = 0;
    if(n==1) 
    {
        movecount++;
        abc_count[c]++;
        cout<<a<<"--->"<<c<<endl;
    }
    else{
        hannoi(n-1,a,c,b);
        movecount++;
        abc_count[c]++;
        cout<<a<<"--->"<<c<<endl;
        hannoi(n-1,b,a,c);
        
    }
}
int main()
{
    int n;
    cin>>n;
    hannoi(n,0,1,2);
    cout<<movecount<<' '<<abc_count[0]<<' '<<abc_count[1]<<' '<<abc_count[2];
	return 0;
}
