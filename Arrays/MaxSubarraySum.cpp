#include<bits/stdc++.h>
using namespace std;

//using kadane's algo
//it assumes at least 1 positive no is there in array
int maxSubarraySum(int *arr,int n)
{
	int ms=INT_MIN,cs=0;
	int maxEle=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cs+=arr[i];
		if(cs<0)
			cs=0;
		maxEle=max(maxEle,arr[i]);
		ms=max(ms,cs);
	}
	if(ms==0)
		return maxEle;
	return ms;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<maxSubarraySum(arr,n)<<endl;
	}
	return 0;
}