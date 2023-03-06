#include <iostream>
using namespace std;
int main()
{
 //encrypt
    int n, m, a, b, c, d;
    cin >> n >> m;
    d = n % 10;
    c = (n / 10) % 10;
    b = (n / 100) % 10;
    a = n / 1000;
    a = (a + 7) % 10;
    b = (b + 7) % 10;
    c = (c + 7) % 10;
    d = (d + 7) % 10;
    int result1=c * 1000 + d * 100 + a * 10 + b ;
   // decrypt
    d = m % 10;
    c = (m / 10) % 10;
    b = (m / 100) % 10;
    a = m / 1000;
    a = (a + 3) % 10;
    b = (b + 3) % 10;
    c = (c + 3) % 10;
    d = (d + 3) % 10;
cout <<result1<<" "<< c * 1000 + d * 100 + a * 10 + b << endl;
    return 0;
}