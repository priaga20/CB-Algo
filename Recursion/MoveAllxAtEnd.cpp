#include <iostream>
#include<string>
using namespace std;

void moveAllxToEnd(string &s,int i,int n)
{
	if(i==n)
		return;
	if(s[i]=='x'){
		s= s.substr(0,i)+s.substr(i+1)+"x";
	}
	
	moveAllxToEnd(s,i+1,n);
}

int main()
{
	string s;
	cin>>s;

	moveAllxToEnd(s,0,s.size());

	cout<<s;
	return 0;
}