#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    char ch[30];
    char ans[30][30] = {'\0'};
    int x = 0;
    int y = 0; //保存
    cin >> n;
    cin.get();
    cin.getline(ch, 30);
    int time = 2 * n - 2; //周期
    int len = strlen(ch);
    if (n == 1 || n >= len)
    {
        cout << ch;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {

            ans[x][y] = ch[i];
            if (i % time < n - 1)
                x++;
            else
            {
                x--;
                y++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int m = 0; m <= y; m++)
                cout << ans[j][m];
        }
    }
    return 0;
}