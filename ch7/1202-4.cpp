#include <iostream>
using namespace std;
char *strrchr(char *str, char ch)
{
    char *temp;
    temp=NULL;
    while (*str)
    {
        if (*str == ch)
        {
            temp=str;
        }
        str++;
    }
    return temp;
}

int main()
{
    char str[50]={'\0'};
    char ch;
    cin.getline(str, 50);
    cin >> ch;
    if(strrchr(str, ch))
    cout << strrchr(str, ch);
    else cout<<"no";
    return 0;
}
