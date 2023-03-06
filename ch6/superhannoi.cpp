#include <iostream>
using namespace std;
const int p0=0,p1=1,p2=2;

void move(int from, int to, int m)
//把一个盘子从from柱子，移动到to柱子，m是游戏的总人数
{
    /*请在此处添加代码*/
    static int i=0;
    cout<<"s"<<i%m<<":";
    i++;
    cout<<from<<"->"<<to<<endl;
    
}

void  Hanoi(int n, int m, int start, int finish, int temp)
//n：汉诺塔盘子的个数，m：参加游戏的总人数
//本程序实现把n个盘子从start柱子，移动到finish柱子
//temp是临时中转的柱子。
//本函数不必修改
{
    if (n==1)
        move(start, finish,m);
    else
    {
        Hanoi(n-1, m, start, temp, finish);
        move(start, finish,m);
        Hanoi(n-1, m, temp, finish, start);
    }
}
//主函数不必修改
int main()
{
    int n,m;  //n是汉诺塔盘子个数，m是参加游戏的总人数
    cin>>n>>m;
    Hanoi(n,m, p0,p1,p2);
    return 0;
}
