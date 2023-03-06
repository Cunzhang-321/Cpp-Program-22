#include "Longlongint.h"
#include<iostream>
#include<cstring>
using namespace std;

void bigInt::show()
{
    if(*ch==48)
    cout<<ch+1<<endl;
    else cout<<ch<<endl;
}
void bigInt::read()
{
    char *ch1= new char [100]; //临时读取用
    cin>>ch1;
    digi=strlen(ch1);
    ch = new char [digi+1]; //存储用
    strcpy(ch,ch1);
    //*(ch+digi)='\0';
    delete[] ch1;
}
bigInt sum(bigInt a,bigInt b)
{
    bigInt res;
    bigInt *max=&a;
    bigInt *min=&b;
    if(a.digi<b.digi)  //让指针指向位数大和位数小的对象，方便后面计算
    {
        max=&b;
        min=&a;
    }
    res.ch=new char [(*max).digi+2];
    char *temp=new char [res.digi+1];
    *(res.ch)=48;        //以防最高位进位，第一位留个0
    //int i;
    for(int i=0;i<(*max).digi-(*min).digi;i++)
    {
        temp[i]='0';
    }
    temp[(*max).digi-(*min).digi]='\0';
    strcat(temp,(*min).ch);
    res.ch[(*max).digi]=temp[(*max).digi-1]+(*max).ch[(*max).digi-1]-48;
    for(int j=(*max).digi-1;j>0;j--)
    {
        res.ch[j]=temp[j-1]+(*max).ch[j-1]-48;
        if(res.ch[j+1]>57)
        {
            res.ch[j+1]-=10;
            res.ch[j]++;
        }
    }
    if(res.ch[1]>57)
        {
            res.ch[1]-=10;
            res.ch[0]=49;
        }
        else res.ch[0]=48;

                delete[] temp;
                return res;
}
