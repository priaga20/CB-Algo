#include<iostream>
using namespace std;

int printLastIndex(int *arr, int n, int t)
{
	if(n==0)
		return -1;

	int smallAns=printLastIndex(arr+1,n-1,t);

	if(smallAns!=-1)
		return 1+smallAns;

	if(arr[0]==t)
		return 0;

	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int *arr = new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int t;
	cin>>t;

	cout<<printLastIndex(arr,n,t);
	return 0;
}