#include<iostream>
#include<cstring>
using namespace std;
void add_float(char* a, char* b, char* res);
int main()
{
    
    char a[128]={'\0'}; //两个浮点数
    char b[128]={'\0'};
    char res[128]={'\0'}; //结果
    cin>>a;cin>>b;
   // cin.getline(a,128);
   // cin.getline(b,128);
    add_float(a,b,res);
    cout<<res<<endl;
    return 0;
}
void add_float(char* a,char* b,char* res)
{
    int ia=0,ib=0;
    int inte_a=0;  //a的整数部分
    int inte_b=0; //b的整数部分
    char q[127]={'\0'}; //结果的小数部分
    while(a[ia]!='.')
    {
        inte_a=inte_a*10+a[ia]-48;
        ia++;
    }
    while(b[ib]!='.')
    {
        inte_b=inte_b*10+b[ib]-48;
        ib++;
    }
    int inte_res;
    inte_res=inte_a+inte_b;
    ia++;ib++;
    int iq=0;
    //int tempa=ia,tempb=ib; //记录ia和ib的值
    while(b[ib]&&a[ia]) //小数部分加法
    {
        q[iq]=a[ia]+b[ib]-48;
        ia++;ib++;iq++;
    }
    while(b[ib]||a[ia]) //小数部分加法
    {
        q[iq]=a[ia]+b[ib];
        ia++;ib++;iq++;
    }
    for(int j=iq-1;j>0;j--) //进位
    {
        if(q[j]>=58)
        {q[j]-=10;q[j-1]++;}
    }
    if(q[0]>=58) {q[0]-=10;inte_res++;} 
    iq=strlen(q)-1;
    while(q[iq]==48) //去除多余的0
    {
        q[iq]='\0'; iq--;
    }
    if(!inte_res)
    {*res=46;strcat(res,q);}
    else
    {
        int m=0;
        while(inte_res)
        {
            res[m]=inte_res%10+48;
            inte_res/=10;
            m++;
        }
        char temp;
        for(int n=0;n<m/2;n++) //逆序排列整数部分
        {
            temp=res[n];
            res[n]=res[m-1-n];
            res[m-1-n]=temp;
        }
        res[m]=46;strcat(res,q);
    }
}