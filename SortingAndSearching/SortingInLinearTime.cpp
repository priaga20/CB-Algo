#include<iostream>
using namespace std;

void sort(int* arr,int n)
{
    int s=0,e=n-1,mid=0;
    while(mid<=e)
    {
        if(arr[mid]==2)
        {
            swap(arr[mid],arr[e]);
            e--;
        }
        else if(arr[mid]==1)
        {
           mid++;
        }
        else
        {
            swap(arr[mid],arr[s]);
            s++;
            mid++;
        }
    }
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    delete [] arr;
    arr=0;
	return 0;
}