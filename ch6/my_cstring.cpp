#include <iostream>
using namespace std;
char *my_strchr(char *str, char c);
char *my_strstr(char *str1, char *str2);
void my_memset(char *ptr, char value, int num);

int main()
{
    char str1[100];
    char str2[100];
    char *p_1, *p_2;

    cin.getline(str1, 100, '\n'); //输入查找字符串
    cin.getline(str2, 100, '\n'); //输入目标字符串

    p_1 = my_strchr(str1, 's');  //在string1中查找第一个出现的‘s’的地址
    p_2 = my_strstr(str1, str2); //在string2中查找第一个出现的字符串str2的地址
    int i = 0, j = 0, k = 0;

    /***my_strchr***/
    if (p_1 != NULL)
    {
        i = p_1 - str1;
        cout << "在str1中s第一次出现在第" << i + 1 << "个位置" << endl;
    }
    else
        cout << "未匹配到's'" << endl;

    /***my_strstr***/
    if (p_2 != NULL)
    {
        j = p_2 - str1;
        cout << "在str2中目标字符串第一次出现在第" << j + 1 << "个位置" << endl;
    }
    else
        cout << "未匹配到字串" << endl;

    /***my_memset***/
    my_memset(str1, 's', 3); //内存修改
    while (*(str1 + k))
    {
        cout << *(str1 + k); //思考下这里为什么不能使用str++来遍历
        k++;
    }
    cout << endl;
    return 0;
}

/***字符查找函数***/
//输入查找字符串地址与目标字符
//返回出现的第一个目标字符地址
//如果没有找到，返回空指针NULL
char *my_strchr(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
        {
            return str;
        }
        str++;
    }
    return (NULL);
}

/***字符串查找函数***/
//输入查找字符串首地址与目标字符串首地址（或是目标字符数组首地址）
//返回出现的第一个字符串首地址
//如果没有找到，返回空指针NULL
char *my_strsatr(char *str1, char *str2)
{
    char *s1 = str1;
    char *s2 = str2;
    char *temp = str1;
    while (*temp)
    {
        s1 = temp;
        s2 = str2;
        //判断是否匹配 否则跳出
        while (*s1 && *s2 && *s1 == *s2)
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
            return temp; //找到
        temp++;
    }
    return NULL;
}

/***内存修改函数***/
//输入修改字符串起始地址，修改字符与修改长度
//返回修改后的字符串首地址

void my_memset(char *ptr, char value, int num)
{
    for (int i = 0; i < num; i++)
    {
        *ptr = value;
        ptr++;
    }
}
