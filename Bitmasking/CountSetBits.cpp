#include<iostream>
using namespace std;

int countSetBits(int n)
{
	int ans=0;
	while(n>0)
	{
		int last_bit=(n&1);
		ans+=last_bit;
		n=n>>1;
	}
	return ans;
}

//optimised
int countSetBitsOptimised(int n)
{
	int ans=0;
	while(n>0)
	{
		n= n&(n-1);
		ans++;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;   // i is lower index and j is higher index
	cout<<countSetBits(n)<<endl;
	cout<<countSetBitsOptimised(n)<<endl;
}