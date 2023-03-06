#include <iostream>
using namespace std;
int main()
{
    char ch[80];
    char s[80];
    int counter = 0;
    int i = 0;
    cin.getline(ch, 80);
    while (ch[i] != '\0')
    {
        if (i % 2 == 1)
        {
            s[counter] = ch[i];
            counter++;i++;
        }
        else
            i++;
    }
    for(int j=0;j<counter;j++)
    cout<<s[j];
    return 0;
}