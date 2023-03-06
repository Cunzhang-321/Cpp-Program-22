#include <iostream>
using namespace std;
bool if_run(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}
char *julian(int year, int day)
{
    char *out;
    out = new char[7];
    int i = 0; //月份计数器
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (if_run(year))
    {
        if (day > 366)
            return NULL;
        m[2] = 29;
    }
    else
    {
        if (day > 365)
            return NULL;
    }
    for (i = 0; i < 13; i++)
    {
        day = day - m[i];
        if (day <= 0)
            break;
    }
    day = day + m[i];
    switch (i) //月份输出
    {
    case 1:
       { *out='J';out++;*out='a';out++;*out='n';
        break;}
    case 2:{ *out='F';out++;*out='e';out++;*out='b';
        break;}
         case 3:{ *out='M';out++;*out='a';out++;*out='r';
        break;}
         case 4:{ *out='A';out++;*out='p';out++;*out='r';
        break;}
         case 5:{ *out='M';out++;*out='a';out++;*out='y';
        break;}
         case 6:{ *out='J';out++;*out='u';out++;*out='n';
        break;}
         case 7:{ *out='J';out++;*out='u';out++;*out='l';
        break;}
         case 8:{ *out='A';out++;*out='u';out++;*out='g';
        break;}
         case 9:{ *out='S';out++;*out='e';out++;*out='p';
        break;}
         case 10:{ *out='O';out++;*out='c';out++;*out='t';
        break;}
         case 11:{ *out='N';out++;*out='o';out++;*out='v';
        break;}
         case 12:{ *out='D';out++;*out='e';out++;*out='c';
        break;}
    default:
        break;
    }
    out++;*out=' ';out++;
        *out=char(day/10+'0'); //十位数
        out++;
        *out=char(day%10+'0');//个位数
        out++;*out='\0';
    
    out-=6;
    return out;
}
int main()
{
    int year, day;
    char *res;
    cin >> year >> day;
    res = julian(year, day);
    cout << res << endl;
    delete[] res;
    return 0;
}
