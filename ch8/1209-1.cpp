#include <iostream>
using namespace std;
struct clockT
{
    int hh;
    int mm;
    int ss;
};
void setTime(clockT *cl, int h, int m, int s)
{
    cl->hh = h;
    cl->mm = m;
    cl->ss = s;
}
void showTime(clockT cl)
{
    char h[3], m[3], s[3];
    h[2]=m[2]=s[2]='\0';
    h[1] = cl.hh % 10 + '0';
    h[0] = cl.hh / 10 + '0';
    m[1] = cl.mm % 10 + '0';
    m[0] = cl.mm / 10 + '0';
    s[1] = cl.ss % 10 + '0';
    s[0] = cl.ss / 10 + '0';
    cout<<h<<":"<<m<<":"<<s<<endl;
}
void increase(clockT *cl)
{
    cl->ss++;
    if (cl->ss == 60)
    {
        cl->mm++;
        cl->ss = 0;
    }
    if (cl->mm == 60)
    {
        cl->hh++;
        cl->mm = 0;
    }
    if (cl->hh == 24)
    {
        cl->hh = 0;
    }
}
int main()
{
    clockT myclock1,myclock2;
    int hh1, mm1, ss1,hh2,mm2,ss2;
    cin >> hh1 >> mm1 >> ss1>> hh2 >> mm2 >> ss2;
    setTime(&myclock1, hh1, mm1, ss1);
    setTime(&myclock2, hh2,mm2,ss2);
    //clock1
    showTime(myclock1);
    increase(&myclock1);
    showTime(myclock1);
    //clock2 
    showTime(myclock2);
    increase(&myclock2);
    showTime(myclock2);
    return 0;
}
