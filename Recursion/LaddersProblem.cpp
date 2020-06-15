#include<iostream>
using namespace std;

int totalWays(int n, int k)
{
	if(n==0)
		return 1;  //1 way to stand on ground

	if(n<0)
		return 0;

	int ans =0;
	for(int i=0;i<k;i++)
	{
		ans+=totalWays(n-i,k);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;

	cout<<totalWays(n,k);
	return 0;
}