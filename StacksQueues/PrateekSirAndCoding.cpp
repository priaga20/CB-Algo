#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int q;
	cin>>q;
	stack<int> s;
	while(q--)
	{
		int t;
		cin>>t;
		if(t==2)
		{
			int c;
			cin>>c;
			s.push(c);
		}
		else 
		{
			if(!s.empty())
			{
				cout<<s.top()<<endl;
				s.pop();
			}
			else
				cout<<"No Code"<<endl;
		}
	}
}