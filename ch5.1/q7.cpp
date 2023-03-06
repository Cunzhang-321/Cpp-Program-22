#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[100];
    cin.getline(s, 100);
    int start = 0;
    int move;
    int index;
    int max_length = 0; //最大长度

    for (move = 0; move < strlen(s); ++move) //大循环
    {
        for (index = start; index < move; ++index)
        {
            if (s[index] == s[move])
            {
                // start_move下一个位置
                start = index + 1;
                break;
            }
        }

        //比较
        if (move - start + 1 > max_length)
        {
            max_length = move - start + 1;
        }
    }
    cout << max_length;
    return 0;
}