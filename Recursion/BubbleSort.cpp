#include<iostream>
using namespace std;

void bubbleSort(int *arr,int n,int i,int j)
{
	if(i==n-1 || j==n)
		return;

	if(arr[j]<arr[i])
		swap(arr[i], arr[j]);

	if(j<n)
		bubbleSort(arr,n,i,j+1);

    bubbleSort(arr,n,i+1,i+2);
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

	bubbleSort(arr,n,0,1);

    for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}    

	return 0;
}