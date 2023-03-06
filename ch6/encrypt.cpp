#include<iostream>
using namespace std;
int enc[]={8,7,3,4,9,6,2};
/****
定义与实现子函数
****/
void encrypt(char *input,char *encry)
{
    int i=0;
    int temp;
    while(*input)
    {
        temp=*input+enc[i%7];
        if(temp>122)
        temp=temp%91;
        *encry=temp;
        input++;encry++;
        i++;
    }
}
void decrypt(char *encry,char *decry)
{
    int i=0;
    int temp;
    while(*encry)
    {
        temp=*encry-enc[i%7];
        if(temp<32)
        temp=temp+91;
        *decry=temp;
        decry++;encry++;
        i++;
    }

}

/***********/


int main()
{
/*********** Start *****************/
    char input[30]={'\0'};
    char encry[30]={'\0'};
    char decry[30]={'\0'};
    cin.getline(input,30);
    encrypt(input,encry);
    decrypt(encry,decry);
    cout<<encry<<endl<<decry;
	return 0;
/*********** End *****************/
}
