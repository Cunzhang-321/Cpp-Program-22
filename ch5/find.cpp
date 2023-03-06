#include <iostream>
using namespace std;
int main()
{
	
	char n;
	char s[80];
	int counte = -1;
	cin.getline(s,80);
    cin.get(n); 
	for(int i=0;s[i]!=0;i++){
		if(n==s[i]){
			counte = i;
		}
	} 
	if(counte == -1){
		cout<<"Not Found";
	}else{
		cout<<counte;
	}
	return 0;
}