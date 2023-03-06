#include <iostream>
using namespace std;
#define PI 3.14
int main()
{
    double r;
    cout << "请输入半径" << endl;
    cin >> r;
    double S, C;
    S = PI * r * r;
    C = 2 * PI * r;
    cout << "面积为" << S << '\n'
         << "周长为" << C << endl;
    return 0;
}
