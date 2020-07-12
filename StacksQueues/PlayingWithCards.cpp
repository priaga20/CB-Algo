#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	stack<int> a;
	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		a.push(v);
	}

	//making prime seive
	int *primes=new int[100001]();
	vector<int> seive;
	for(int i=3;i<100001;i+=2)
	{
		primes[i]=1;
	}
	primes[2]=1;
	seive.push_back(2);
	for(int i=3;i*i<100001;i+=2)
	{
		if(primes[i])
		{
			seive.push_back(i);
			for(int j=i*i;j<100001;j+=i)
			{
				primes[j]=0;
			}
		}
	}

	//handling queries
	vector<stack<int>> v;
	for(int i=0;i<q;i++)
	{
		int p=seive[i];
		stack<int> b;
		stack<int> tempa;
		while(!a.empty())
		{
			if(a.top()%p==0)
				b.push(a.top());
			else
				tempa.push(a.top());
			a.pop();
		}
		v.push_back(b);
		tempa.swap(a);
	}

	//printing output
	for(int i=0;i<v.size();i++)
	{
		stack<int> b=v[i];
		while(!b.empty())
		{
			cout<<b.top()<<endl;
			b.pop();
		}
	}
	while(!a.empty())
	{
		cout<<a.top()<<endl;
		a.pop();
	}
}