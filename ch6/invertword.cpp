#include<iostream>
using namespace std;


int wordReverse(char *s,char wd[10][20])
{
 int i,j=0,k=0;
 for(i=0;s[i];i++)
 {
  if(s[i]!=' ')
   wd[j][k++]=s[i];
  else
  {wd[j][k]='\0';
  j++;
  k=0;
  }
 }
 wd[j][k]='\0';

 return j;
}

int main()
{
 int i,n;
 char str[100],word[10][20];
 gets(str);
 n=wordReverse(str,word);
  cout<<n+1<<endl;
 for(i=n;i>=0;i--)
  printf("%s ",word[i]);

 return 0;
}