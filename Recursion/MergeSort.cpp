#include<iostream>
using namespace std;

void merge(int *arr,int s,int e)
{
	int mid=(s+e)/2;
	int i=s,j=mid+1,k=0;
	int *temp =new int [e-s+1];

	while(i<=mid && j<=e)
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}

	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=e)
	{
		temp[k++]=arr[j++];
	}

	k=0;
	for(int i=s;i<=e;i++)
	{
		arr[i]=temp[k++];
	}
}

void mergeSort(int *arr,int s,int e)
{
	if(s<e)
	{
		int mid = (s+e)/2;
		mergeSort(arr,s,mid);
		mergeSort(arr,mid+1,e);
		merge(arr,s,e);
	}
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

	mergeSort(arr,0,n-1);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}