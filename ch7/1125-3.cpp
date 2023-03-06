#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    /*Start your code here*/
    int *A;
    int index = 0;
    int count = 0;
    int sum = 0;
    A = new int[n];
    for (int j = 0; j < n; j++)
        A[j] = 1; //表示第i个人是否还在圈子中 1=true

    while (true)
    {
        sum = 0;
        if (A[index])
        {
            if (count == 2)
            {
                A[index] = 0; // kick off
            }
            count = (count + 1) % 3;
        }
        index = (index + 1) % n;
        for (int j = 0; j < n; j++)
            sum += A[j];
        if (sum == 1)
            break;
    }

    for (int j = 0; j < n; j++)
        if(A[j])
        cout << j+1;
    /*end your code*/
    return 0;
}
