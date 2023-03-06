#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 160
int main()
{
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
int l3;
    cin.getline(str1, MAX_SIZE);
    cin.getline(str2, MAX_SIZE);
    int l1=strlen(str1);
    if(strstr(str1,str2)!=NULL)
{    char *temp=strstr(str1,str2);
    l3=strlen(temp);}
    else l3=l1+1;
    if(l1-l3>=0) cout<<l1-l3;
    else cout<<-1;
    return 0;
}