#include <iostream>
using namespace std;
void getDate(int &dd, int &mm, int &yy)
{
    int i = 0;
    char ch[10]={'\0'};
    cin.getline(ch, 10);
    dd = int(ch[0] - '0');
    if (ch[1] == '-')
        i = 2;
    else
    {
        dd = dd * 10 + int(ch[1] - '0');
        i = 3;
    }
    switch (ch[i])
    {
    case 'F':
    {
        mm = 2;
        break;
    }
    case 'S':
    {
        mm = 9;
        break;
    }
    case 'O':
    {
        mm = 10;
        break;
    }
    case 'N':
    {
        mm = 11;
        break;
    }
    case 'D':
    {
        mm = 12;
        break;
    }
    default:
    {
        switch (ch[i + 2])
        {
        case 'l':
        {
            mm = 7;
            break;
        }
        case 'g':
        {
            mm = 8;
            break;
        }
                case 'y':
        {
            mm = 5;
            break;
        }
        default:
        {
            if (ch[i] == 'M')
                {mm = 3;break;}
            if (ch[i] == 'A')
               { mm = 4;break;}
                if (ch[i+1] == 'a')
               { mm = 1;break;}
                if (ch[i+1] == 'u')
               { mm =6 ;break;}
        }
        }
    }
    break;
    }
    i+=4;
    yy=int(ch[i]-'0');
    if(ch[i+1])
    {
        yy=yy*10+int(ch[i+1]-'0');
    }
}
int main()
{
    int day, month, year;
    getDate(day, month, year);
    cout << day << " " << month << " " << year << endl;
    return 0;
}
