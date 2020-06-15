#include <iostream>
#include<string>
using namespace std;

void removeDuplicates(string &s,int i)
{
	if(i==s.size()-1)
		return;

	if(s[i]==s[i+1])
		s=s.substr(0,i)+s.substr(i+1);
	else
		i++;
	removeDuplicates(s,i);
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	removeDuplicates(s,0);
	cout<<s;
	return 0;
}