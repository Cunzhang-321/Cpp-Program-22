 #include <iostream>
using namespace std;
void delChar(char str[], char c)
{	
	if(*str){
	if(*str==c)
	{
		for(int i=0;str[i]!='\0';i++)
		str[i]=str[i+1];
	}
	delChar(str+1,c);}
	else return;
}
int main()
{
  char deptName[]={"eeeeee"};
   delChar(deptName,'e');
   char *ptr=deptName;
   cout<<ptr;
  return 0;
}
