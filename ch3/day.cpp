#include <iostream>
using namespace std;
int main()
{
    int yy, mm, dd, daynum;
    bool run;
        cin >> yy >> mm >> dd;

    run = yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0;
    if (mm < 1 || mm > 12)
        cout << "Illegal";
    if (mm == 1)
    {
        if (dd >= 1 && dd <= 31)
        {
            daynum = dd;
            cout << daynum;
        }
        else
            cout << "Illegal";
    }

    if (mm == 2)
    {
        if (run)
        {
            if (dd >= 1 && dd <= 29)
            {
                daynum = 31 + dd;
                cout << daynum;
            }
            else
                cout << "Illegal";
        }
        else
        {
            if (dd >= 1 && dd <= 28)
            {
                daynum = 31 + dd;
                cout << daynum;
            }
            else
                cout << "Illegal";
        }
    }

    if (mm >= 3 && mm <= 12)
    {
        if (mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        {
            if (dd >= 1 && dd <= 31)
            {
                if (run)
                {
                    daynum  = 31 * (mm - 1) + dd - (4 * mm + 23) / 10 + 1;
                    cout << daynum;
                }
                else
                {
                    daynum = 31 * (mm - 1) + dd - (4 * mm + 23) / 10;
                    cout << daynum;
                }
            }
            else
                cout << "Illegal";
        }
        else
        {
            if (dd >= 1 && dd <= 30)
            {
                if (run)
                {
                    daynum = 31 * (mm - 1) + dd - (4 * mm + 23) / 10 + 1;
                    cout << daynum;
                }
                else
                {
                    daynum  = 31 * (mm - 1) + dd - (4 * mm + 23) / 10;
                    cout << daynum;
                }
            }
            else
                cout << "Illegal";
        }
    }

    return 0;
}
