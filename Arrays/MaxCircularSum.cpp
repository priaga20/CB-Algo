#include <iostream>
using namespace std;

int kadane(int *arr,int n)
{
    int cs=0,ms=0;
    for(int i=0;i<n;i++)
    {
        cs+=arr[i];
        if(cs<0)
            cs=0;
        ms=max(cs,ms);
    }
    return ms;
}

int main() {
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int *arr1=new int[n];
        int *arr2=new int[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
            arr2[i]=-arr1[i];
            sum+=arr1[i];
        }
        int ans1=kadane(arr1,n);
        int ans2=kadane(arr2,n)+sum;
        if(ans1>ans2)
            cout<<ans1<<endl;
        else
            cout<<ans2<<endl;
    }
}
