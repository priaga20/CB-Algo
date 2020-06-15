#include<iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
	int pivotEle = arr[e];
	int i=s,j=s;
	while(j<e)
	{
		if(arr[j]<=pivotEle)
		{
			swap(arr[i],arr[j]);
			i++;
		}
		j++;
	}
	swap(arr[i],arr[e]);
	return i;
}

void quickSort(int *arr,int s,int e)
{
	if(s<e)
	{
		int pIndex = partition(arr,s,e);
		quickSort(arr,s,pIndex-1);
		quickSort(arr,pIndex+1,e);
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

	quickSort(arr,0,n-1);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}