
#include<bits/stdc++.h>
using namespace std;
char lib(int m)
{
    if (m < 10)
        return m + '0';
    else
        return m - 10 + 'A';
}
string change(int n, int b)//进制转换
{
    string res;
    while (n){
        res += lib(n % b);
        n /= b;
    }
    reverse(res.begin(), res.end());//翻转使高位在左侧
    return res;
}
int main()
{
    int n1, n2, B, j,temp;
    bool judge = true;
    cin >> B;
    int i = 0;
    char ch[20];
    for (n1 =1 ; n1 <= 200; n1++)
    {
        temp=n2 = n1 * n1;
        i=0;
        judge=true;
        while (temp)
        {
            ch[i++] = lib(temp % B);
            temp /= B;
        }
        for (j = 0; j < i/2; j++)
        {
            
            if (ch[j] != ch[i-1 - j])
                judge = false;
        }
        if (judge)
            {cout << change(n1,B) << " " <<change(n2,B) << endl;      
            }
    }
    return 0;
}