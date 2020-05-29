#include <iostream>
using namespace std;

int searchElement(int *arr, int n, int target) {
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[s]<=arr[mid])  //left half sorted
            {
                if(target<=arr[mid] && target>=arr[s])
                    e=mid-1;
                else
                    s=mid+1;
            }
            else if(arr[e]>=arr[mid])  //right half sorted
            {
                if(target>=arr[mid] && target<=arr[e])
                    s=mid+1;
                else
                    e=mid-1;
            }
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
    int k;
    cin>>k;
    int ans=searchElement(arr,n,k);
    cout<<ans;
    delete [] arr;
    arr=0;
}