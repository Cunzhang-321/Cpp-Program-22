#include <iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

void maxmax(int a[],int n,int *p1max,int *p2max); //array number firstmax secmax
int main()
{
    int n;
    cin >> n;
    int *num = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int max, sec;
    maxmax(num, n, &max, &sec);
    cout << max << " " << sec << endl;

    return 0;
}
void maxmax(int a[],int n,int *p1max,int *p2max)
{
    
    switch (n)
    {
    case 1:
        *p1max=a[0];*p2max=-114514;
        return;
    case 2:
            *p1max = max(a[1],a[0]);
            *p2max = min(a[1],a[0]);
        return;
    default:
        int firmax1,firmax2,secmax1,secmax2;
        maxmax(a,n/2,&firmax1,&secmax1);
        maxmax(a+n/2,n-n/2,&firmax2,&secmax2);
        //*p1max=max(firmax1,firmax2);
        if(firmax1>firmax2)
        {
            *p1max=firmax1;
            *p2max=max(firmax2,secmax1);
        }
        else
        {
            *p1max=firmax2;
            *p2max=max(firmax1,secmax2);
        }
        return;
    }
}