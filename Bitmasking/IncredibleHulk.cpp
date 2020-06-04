#include<iostream>
using namespace std;

int incredibleHulk(int n)
{
	//basically have to count the number of set bits
	int ans=0;
	while(n>0)
	{
		n=n&(n-1);
		ans++;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<incredibleHulk(n)<<endl;
	}
}