#include<iostream>
using namespace std;

void printAllIndices(int *arr, int n, int i, int t)
{
	if(i==n)
		return;

	if(arr[i]==t)
		cout<<i<<" ";

	printAllIndices(arr, n, i+1, t);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int *arr= new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int t;
	cin>>t;

	printAllIndices(arr,n,0,t);
	return 0;
}