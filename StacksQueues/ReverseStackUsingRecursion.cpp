#include <iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &s, int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	insertBottom(s,x);
	s.push(y);
}

void reverse(stack<int> &s)
{
	if(s.empty())
		return;
	int x= s.top();
	s.pop();
	reverse(s);
	insertBottom(s,x);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	stack<int> s;
	while(n--)
	{
		int v;
		cin>>v;
		s.push(v);
	}
	reverse(s);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}