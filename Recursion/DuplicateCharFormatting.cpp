#include<iostream>
#include<string>
using namespace std;

void dupCharFormatting(string &s, int i)
{
	if(i==s.size()-1)
		return;

	if(s[i]==s[i+1])
	{
		s= s.substr(0,i+1) + "*" + s.substr(i+1);
		i++;
	}
	
	dupCharFormatting(s,i+1);
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	dupCharFormatting(s,0);

	cout<<s;

	return 0;
}