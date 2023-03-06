#include <iostream>
using namespace std;

int main()
{
    /*Start your code here*/
    char *str;
    str=new char[101];
    cin.getline(str,101);
    int i=0,j=0; //单词数
    int m=0;
    int *input; //记录输入顺序
    input=new int[10];
    while(cin>>(input[j]))
    j++;
    char **word=new char *[10]; //存储单词
    word[i]=new char[101]{'\0'};
    while(*str)
    {
        word[i][m]=*str;
        str++;
        if(*str==' ')
        {
            i++;
            word[i]=new char[100]{'\0'};
            m=0;
            str++;
            continue;
        }
        m++;
    }
    cout<<i+1<<endl;
    for(int k=0;k<j;k++)
    cout<<word[input[k]]<<" ";
    /*end your code*/
    return 0;
}
