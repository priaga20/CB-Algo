#include<iostream>
using namespace std;
#define ll long long

int binarySearch(ll int* arr,int n,int key)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(key==arr[mid])
            return mid;
        if(key>arr[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    ll int* arr=new ll int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int ans=binarySearch(arr,n,m);
    cout<<ans;
	return 0;
}