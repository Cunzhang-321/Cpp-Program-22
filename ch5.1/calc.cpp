#include <iostream>
using namespace std;
int pow(int x, int y)
{
    int result = 1;
    for (int i = 1; i <= y; i++)
        result *= x;
    return result;
}
int main()
{
    int a, b, result;
    a = b = 0;
    int l1 = 0;
    int l2 = 0;
    char ch1[10000], ch2[10000];
    char input[1000000];
    cin.getline(input, 1000000);
    for (int i = 0;; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            ch1[l1] = input[i];
            l1++;
        }
        else
            break;
    } //输入a
    for (int i = l1 + 1; input[i] != '\0'; i++)
        if (input[i] >= '0' && input[i] <= '9')
        {
            ch2[l2] = input[i];
            l2++;
        } //输入b

    for (int i = 0; i < l1; i++) // char转换为int a
    {
        int temp = l1-i - 1;
        a+=(ch1[i]-'0')*pow(10,temp);
    }
        for (int i = 0; i < l2; i++) // char转换为int a
    {
        int temp = l2-i - 1;
        b+=(ch2[i]-'0')*pow(10,temp);
    }
    if(input[l1]=='+')
    result=a+b;
        if(input[l1]=='-')
    result=a-b; 
        if(input[l1]=='*')
    result=a*b;
       if(input[l1]=='/')
    result=a/b;
    cout<<a<<input[l1]<<b<<"="<<result;
    return 0;
}