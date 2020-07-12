#include <iostream>
#include<stack>
#include<string>
using namespace std;

string redundantParen(string s)
{
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==')')
		{
			if(st.top()=='(')
				return "Duplicate";
			while(!st.empty() && st.top()!='(')
			{
				st.pop();
			}
			st.pop();  //popping "("
			continue;
		}
		st.push(s[i]);
	}
	return "Not Duplicates";
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		cout<<redundantParen(s)<<endl;
	}
	return 0;
}