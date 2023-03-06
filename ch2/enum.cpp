#include <iostream>
using namespace std;
int main()
{
    enum weekdayT {Sunday, Monday, Tuesday,
                   Wednesday,Thursday,
                   Friday, Saturday
                  };
/*
    cout<<"Sunday\t\t="<<Sunday<<endl;
    cout<<"Monday\t\t="<<Monday<<endl;
    cout<<"Tuesday\t\t="<<Tuesday<<endl;
    cout<<"Wednesday\t="<<Wednesday<<endl;
    cout<<"Thursday\t="<<Thursday<<endl;
    cout<<"Friday\t\t="<<Friday<<endl;
    cout<<"Saturday\t="<<Saturday<<endl;
*/
 //   int      i = 1;
    weekdayT w = Sunday;
    weekdayT w2 = Saturday;
    //weekdayT w3 = (weekdayT)2; 
    weekdayT w3 = weekdayT(2);
    cout << w<<" "<<w2 <<" "<<w3<< endl;
    return 0;
}
