#include<iostream>
using namespace std;

int getCount(int a,int b)
{
	//basically have to count the number of set bits
	int ans=0;
	for(int i=a;i<=b;i++)
	{
		int n=i;
		while(n>0)
		{
			n=n&(n-1);
			ans++;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<getCount(a,b)<<endl;
	}
}