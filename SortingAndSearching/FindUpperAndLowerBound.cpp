#include <iostream>
using namespace std;

int getBound(int *arr,int n,int key,int uOrl)
{
    int s=0,e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            if(uOrl==1)
                s=mid+1;
            else
                e=mid-1;
        }
        else if(arr[mid]<key)
            s=mid+1;
        else
            e=mid-1;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int key;
        cin>>key;
        int lans=getBound(arr,n,key,0);  
        cout<<lans<<" ";
        int uans=getBound(arr,n,key,1);
        cout<<uans<<endl;
    }
    delete [] arr;
    arr=0;
    return 0;
}