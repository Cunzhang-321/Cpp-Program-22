#include <iostream>
using namespace std;

int main()
{
    char str1[20];
    char str2[20];

    cin.getline(str1,20);
    cin.getline(str2,20);

    /*Start your code here*/
    int i=0; //循环
    char temp;//临时存储
        while(str1[i]&&str2[i])
    {
        temp=str1[i];
        str1[i]=str2[i];
        str2[i]=temp;
        i++;
    }
    cout<<str1<<endl<<str2;
    /*end your code*/
    return 0;
}
