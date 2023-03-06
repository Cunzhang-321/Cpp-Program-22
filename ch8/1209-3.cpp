#include <iostream>
using namespace std;
struct day
{
    int yy, mm, dd;
};

struct studentT
{
    char name[21] = {'\0'};
    day birthday;
    char phone[12] = {'\0'};
    char address[51] = {'\0'};
};
void sort(studentT *arra, int n, int *s); // 排序
int main()
{
    int num;
    int s[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    studentT stuarray[9];
    cin >> num;
    cin.get();
    for (int i = 0; i < num; i++)
    {
        scanf("%s%d%d%d%s", stuarray[i].name, &stuarray[i].birthday.yy, &stuarray[i].birthday.mm, &stuarray[i].birthday.dd, stuarray[i].phone);
        cin.get();
        cin.getline(stuarray[i].address, 51);
    }
    sort(stuarray, num, s);
    for (int i = 0; i < num; i++)
    {
        cout << stuarray[s[i]].name << " ";
        cout << stuarray[s[i]].birthday.yy << " " << stuarray[s[i]].birthday.mm << " " << stuarray[s[i]].birthday.dd << " " << stuarray[s[i]].phone << " ";
        cout << stuarray[s[i]].address << endl;
    }
    return 0;
}

void sort(studentT *arra, int n, int *s)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        if (arra[s[j]].birthday.yy < arra[s[j + 1]].birthday.yy)
        {
            temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
        }
        else if (arra[s[j]].birthday.yy == arra[s[j + 1]].birthday.yy)
        {
            if (arra[s[j]].birthday.mm < arra[s[j + 1]].birthday.mm)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
            else if (arra[s[j]].birthday.mm == arra[s[j + 1]].birthday.mm)
            {
                if (arra[s[j]].birthday.dd < arra[s[j + 1]].birthday.dd)
                {
                    temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }
    }
}