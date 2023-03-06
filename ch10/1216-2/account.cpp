#include "account.h"
#include <iostream>

using namespace std;
void SavingAccount::display()
{

	cout<<num<<" "<<money<<" "<<rate<<endl;
}
void SavingAccount::calculate()
{
	money=money*(1+rate);
}
void  SavingAccount::changerate(float new_rate)
{
	rate=new_rate;
}
