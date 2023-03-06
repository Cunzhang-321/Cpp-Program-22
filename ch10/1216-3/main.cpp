#include <iostream>
#include "clock.h"
using namespace std;

int main() {
	char a[9];char b[9];
	cin>>a;cin>>b;
	myclock c0,c1,res;
	c0.readtime(a);
	c1.readtime(b);
	calc(c0,c1,res);
	res.displaytime();
    return 0;
}


