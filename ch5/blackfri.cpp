#include <iostream>
using namespace std;

int run(int year)
{
    if(year%4==0&&year%100!=0||year%400==0) return 1;
    else return 0;
}
int main()
{
    int n,year,daynum;
    int counter[7]={0}; //计数器
    int monthd[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //每个月天数
    cin>>n;
    daynum=13; //初始化总天数
    for(int i=0;i<n;i++) //年份循环
    {
        year=1900+i;
        for(int j=0;j<12;j++)
        {
            if(j==1&&run(year)==1)
            {
                daynum=daynum+monthd[j]+1;
                counter[daynum%7]++;
            }
            else{
                daynum=daynum+monthd[j];
                counter[daynum%7]++;
            }
        }
    }
    counter[daynum%7]--;
    counter[6]++;
    for(int k=1;k<7;k++)
    cout<<counter[k]<<" ";
    cout<<counter[0];
    return 0;
}