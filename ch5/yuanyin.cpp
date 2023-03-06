#include<iostream>
using namespace std;
int main()
{
char ch[80];
int i=0;
int counter=0;
cin.getline(ch,80);
while(ch[i])
{
    if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u'||ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')
    {
        counter++;
    }
    i++;
}
cout<<counter;
return 0;
}