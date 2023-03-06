#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    if ((a < 11 && b < 11) || (a - b < 2 && b - a < 2))
        cout << "In progress";
    if ((a == 11 && a - b > 2) || (a > 11 &&a - b == 2))
        cout << "A win";
    if ((b == 11 && b - a > 2) || (b > 11 &&b - a == 2))
        cout << "B win";
    if ((a - b > 2 || b - a > 2)&&(a > 11 || b > 11))
        cout << "Illegal";
    return 0;
}