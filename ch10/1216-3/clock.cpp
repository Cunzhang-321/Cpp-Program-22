#include "clock.h"
#include <iostream>
using namespace std;
/*myclock::myclock(int h,int m,int s) {
	hh=h;
	mm=m;
	ss=s;
}*/
void  myclock::change(int h1,int m1,int s1)
{
	hh=h1;
	mm=m1;
	ss=s1;
}
void myclock::displaytime() {
	char ch[9];
	ch[0]=hh/10+48;ch[1]=hh%10+48;
	ch[3]=mm/10+48;ch[4]=mm%10+48;
	ch[6]=ss/10+48;ch[7]=ss%10+48;
	ch[2]=ch[5]=':';
	cout<<ch<<endl;
}
void myclock::readtime(char *a) {
	hh=(a[0]-48)*10+a[1]-48;
	mm=(a[3]-48)*10+a[4]-48;
	ss=(a[6]-48)*10+a[7]-48;
}
void calc(myclock c0,myclock c1,myclock &res)
{
	myclock *max=&c0;
	myclock *min=&c1;
	if(c0.hh<c1.hh)    //ÅÐ¶ÏË­´ó
		{max=&c1;min=&c0;}
	else if(c0.hh==c1.hh)
	{
		if(c0.mm<c1.mm)
			{max=&c1;min=&c0;}
		else if(c0.mm==c1.mm)
		{
			if(c0.ss<c1.ss)
			{max=&c1;min=&c0;}
		}
	}
	res.hh=(*max).hh-(*min).hh;
	res.mm=(*max).mm-(*min).mm;
	res.ss=(*max).ss-(*min).ss;
	if(res.ss<0)
	{
		res.ss+=60;
		res.mm--;
	}
	if(res.mm<0)
	{
		res.mm+=60;
		res.hh--;
	}
}
