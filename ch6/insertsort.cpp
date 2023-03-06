#include <iostream>
using namespace std;
void Insert(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[n-1])
        {
            temp = a[n-1];
            for (int j = n-1; j > i; j--)
            {
                a[j] = a[j - 1];
            }
            a[i] = temp;
            break;
        }
    }
} 
void Insert_Sort(int a[], int n)
{
    if (n > 0) //递归的出口是n=0
    {
        Insert_Sort(a, n - 1); //递归实现，将前面n-1个元素排序好
        Insert(a, n);          // 把第n个元素插入到前面n-1个元素中
    }
   // else return;
}
int main()
{
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Insert_Sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}