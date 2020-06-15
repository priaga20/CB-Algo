#include<iostream>
using namespace std;

bool isSorted(int *arr,int i,int n)
{
	if(i==n-1)
		return true;
	if(arr[i]>arr[i+1])
		return false;
	return isSorted(arr,i+1,n);
}

int main()
{
	int n;
	cin>>n;

	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	bool ans=isSorted(arr,0,n);
	if(ans)
		cout<<"True";
	else
		cout<<"False";

	return 0;
}