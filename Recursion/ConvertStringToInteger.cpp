#include<iostream>
#include<string>
using namespace std;

int stringToint(string s, int i)
{
	if(i<0)
		return 0;

	int smallAns = stringToint(s,i-1);
	int d = s[i]-'0';
	return smallAns*10 + d;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<endl;
	cout<<stringToint(s,s.size()-1);

	return 0;
}