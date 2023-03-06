#include <iostream>
#include<cstring>
using namespace std;
#define MAX_SIZE 10001
int main()
{
    int m=0;
    char str[MAX_SIZE];
    cin.getline(str,MAX_SIZE,EOF);
    m=strlen(str);
    int x=0,d=0,a[MAX_SIZE];
    char s[MAX_SIZE];//存储字母
    do
    {
        if((str[x]>='a'&&str[x]<='z')||(str[x]>='A'&&str[x]<='Z'))
        {
            s[d]=str[x];
            a[d]=x;
            d++;
        }
        x++;
    }while(str[x]!='\0');
    s[d]='\0';//提取字母
    int len = d;//字母个数
    int start = 0;//回文字符串起始位置
    int maxlen = 0;//回文最大长度
    int low;//奇数回文中位的前一个
    int high;//奇数回文中位的后一个
    for (int i=1;i<len;i++)//i回文中位
    {
        //回文偶数长
        low=i-1;
        high=i;
        while (low>=0&&high<len&&(s[low]==s[high])||(s[low]==(s[high]-32))||((s[low]-32)==s[high]))
        {
            if ((high-low+1)>maxlen)
             {
               maxlen=high-low+1;
               start=low;
             }
            low--;
            high++;
        }
    }
    for (int i=1;i<len;i++)
    {
        //回文奇数长
        low=i-1;
        high=i+1;
        while (low>=0&&high<len&&(s[low]==s[high])||(s[low]==(s[high]-32))||((s[low]-32)==s[high]))
        {
            if ((high-low+1)>maxlen)
            {
                maxlen=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
    }
    cout<<maxlen<<endl;
    for(int t=a[start];t<=a[start+maxlen-1];t++)
        cout<<str[t];
    return 0;
    }