#include <iostream>
using namespace std;

int main()
{
	int mat[10][10];
	int m, n;
	cin >> m >> n;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	} //输入
	for (int i = 0; i <m; i++)
	{
		for (int j = 0; j <n; j++)
		{
			bool flag = 0; //标记
			for (int x = 0; x <m; x++)
			{
				if (mat[x][j] < mat[i][j])
				{ //判断一列
					flag = 1;
					break;
				}
			}
			for (int x = 0; x<n; x++)
			{
				if (mat[i][x] > mat[i][j])
				{ //判断一行
					flag = 1;
					break;
				}
			}
			if (!flag)
			{		   //满足条件
				ans++; 
				cout <<"mat[" <<i << "][" << j << "]=" << mat[i][j] << "\n";
			}
		}
	}
	if (!ans)
	{ //没有答案
		cout << "Not Found";
	}
	return 0;
}