#include <iostream>
using namespace std;
struct complex
{
    int real;
    int imagine;
};
void printnum(complex x)
{
    if (x.real != 0)
    {
        if (x.imagine == 0)
            cout << x.real << endl;
        else if (x.imagine < 0)
            cout << x.real << x.imagine << "i" << endl;
        else
            cout << x.real << "+" << x.imagine << "i" << endl;
    }
    else
    {
         if (x.imagine == 0)
            cout <<0<< endl;
        else if (x.imagine < 0)
            cout <<x.imagine << "i" << endl;
        else
            cout << x.imagine << "i" << endl;
    }
}
void cadd(complex x, complex y, complex *res) // y加x
{
    res->real = (x.real) + (y.real);
    res->imagine = (x.imagine) + (y.imagine);
}
void ctime(complex x, complex y, complex *res) // y乘x
{
    res->real = (x.real) * (y.real) - (x.imagine) * (y.imagine);
    res->imagine = (x.real) * (y.imagine) + (x.imagine) * (y.real);
}
int main()
{
    complex x, y, res;
    res.imagine = res.real = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    x.real = a;
    x.imagine = b;
    y.real = c;
    y.imagine = d;
    cout << "x = ";
    printnum(x);
    cout << "y = ";
    printnum(y);
    cout << "x += y; x = ";
    cadd(x, y, &res);
    printnum(res);
    x.real = res.real;
    x.imagine = res.imagine;
    cout << "y *= x; y = ";
    ctime(x, y, &res);
    printnum(res);
    y.real = res.real;
    y.imagine = res.imagine;
    cout << "x + y = ";
    cadd(x, y, &res);
    printnum(res);
    cout << "y * x = ";
    ctime(x, y, &res);
    printnum(res);
    cout << "x = ";
    printnum(x);
    cout << "y = ";
    printnum(y);
    return 0;
}
