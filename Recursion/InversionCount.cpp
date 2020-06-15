#include<iostream>
using namespace std;

int merge(int *arr, int n, int s, int e)
{
	int mid = (s+e)/2;
	int i=s,j=mid+1,k=0;
	int *temp = new int[e-s+1];
	int count=0;
	while(i<=mid && j<=e)
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
		{
			count+=(mid-i+1);
			temp[k++]=arr[j++];
		}
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
	return count;
}

int inversionCount(int *arr, int n, int s, int e)
{
	if(s>=e)
		return 0;
	int mid = (s+e)/2;
	int x = inversionCount(arr,n,s,mid);
	int y = inversionCount(arr,n,mid+1,e);
	//inversion count
	int z = merge(arr,n,s,e);
	return x+y+z;
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

	cout<<inversionCount(arr,n,0,n-1);

	return 0;
}