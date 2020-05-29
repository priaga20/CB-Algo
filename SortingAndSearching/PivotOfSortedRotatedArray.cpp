#include <iostream>
using namespace std;

int findPivot(int *arr,int n)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid>s && arr[mid]<arr[mid-1])
            return mid-1;
        else if(mid<e && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]<arr[e]) //right half is sorted
            e=mid-1;
        else                     //left half is sorted
            s=mid+1;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int index=findPivot(arr,n);
    cout<<index;
}

