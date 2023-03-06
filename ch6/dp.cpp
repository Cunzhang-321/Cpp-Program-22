#include <iostream>

using namespace std;

int cal_routines(int m, int n)
{
    int dp[30][30];
    // 初始化
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 1; j < n; j++)
        dp[0][j] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
// 请勿修改mian()函数
int main()
{
    int m, n;
    cin >> m >> n;
    cout << cal_routines(m, n) << endl;
}