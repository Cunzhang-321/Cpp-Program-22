#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /*
    #define DIGI 1.2345678901234567890123456789
    double a,c;
    long double b;
    a = DIGI;b = DIGI; c= 3.77;
    a /=c;b /=c;
    cout<<fixed<<setprecision(30);
    cout<<a<<endl<<b<<endl;
    return 0;*/

    float f1 = 1.2345678901234567890123456789;
    double d1 = 1.2345678901234567890123456789;
    long double dd1 = 1.2345678901234567890123456789;
    cout << fixed << setprecision(40);
    cout << "digi:\t1.23456789012345678901234567890123456789" << endl;
    cout << "f1=\t" << f1 << endl;
    cout << "d1=\t" << d1 << endl;
    cout << "dd1=\t" << dd1 << endl;

    return 0;
}
