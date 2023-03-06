#include <iostream>
using namespace std;
char *oddstr(char *str)
{
    char *newstr;
    int i=0; //记录新字符串长度
    newstr = new char[100];
    str++;
    while (*str)
    {
        *newstr = *str;
        newstr++;
        str += 2;
        i++;
    }
    *newstr='\0';
    return newstr-i;
}
int main()
{
    char str[200]={'\0'};
    cin >> str;
    char *odd = oddstr(str);
    cout << odd << endl;
    delete[] odd;
    return 0;
}
