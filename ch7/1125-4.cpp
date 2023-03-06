//NOT SOLVED！！！！！



#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char *p = new char[200];
    int *d = new int[200];
    cin.getline(p, 200);
    int n = strlen(p);
    if (n > 20)
    {
        cout << "输入不符合要求";
        return 0;
    }
    for (int i = 0; i < n; i++)
        d[i] = 0;
    int epoch = 0;
    while (true)
    {
        // cout<<"this is epoch: "<<epoch<<"-- ";
        epoch += 1;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == 0)
            {
                if (p[i] == 'L' || p[i] == 'l')
                {
                    int clear = 1;
                    int has = 0;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (d[j] == 0)
                        {
                            if (p[j] == '@' || p[j] == '$' || p[j] == '#')
                            {
                                clear = 1;
                                // cout<<"this"<<epoch<<" "<<clear<<endl;
                            }
                            else if (p[j] == '4' && clear == 1)
                            {
                                for (int k = i; k <= j; k++)
                                {
                                    d[k] = 1;
                                }
                                has = 1;
                                break;
                            }
                            else
                            {
                                clear = 0;
                                break;
                            }
                        }
                    }
                    if (has == 1)
                        flag = 1;
                }

                if (p[i] == 'F' || p[i] == 'f')
                {
                    int clear = 1;
                    int has = 0;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (d[j] == 0)
                        {
                            if (p[j] == '@' || p[j] == '$' || p[j] == '#')
                            {
                                clear = 1;
                                // cout<<"this"<<epoch<<" "<<clear<<endl;
                                // cout<<p[j]<<" ";
                            }
                            else if ((p[j] == 'd' || p[j] == 'D') && clear == 1)
                            {
                                for (int k = i; k <= j; k++)
                                {
                                    d[k] = 1;
                                }
                                has = 1;
                                break;
                            }
                            else
                            {
                                clear = 0;
                                break;
                            }
                        }
                    }
                    if (has == 1)
                        flag = 1;
                }
                if (p[i] == 'D' || p[i] == 'd')
                {
                    int clear = 1;
                    int has = 0;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (d[j] == 0)
                        {
                            if (p[j] == '@' || p[j] == '$' || p[j] == '#')
                            {
                                clear = 1;
                                // cout<<"this"<<epoch<<" "<<clear<<endl;
                                // cout<<p[j]<<" ";
                            }
                            else if ((p[j] == '2') && clear == 1)
                            {
                                for (int k = i; k <= j; k++)
                                {
                                    d[k] = 1;
                                }
                                has = 1;
                                break;
                            }
                            else
                            {
                                clear = 0;
                                break;
                            }
                        }
                    }
                    if (has == 1)
                        flag = 1;
                }
            }
        }
        if (flag == 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0)
        {
            cout << p[i];
        }
    }
}