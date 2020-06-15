#include <iostream>
using namespace std;
#define ll long long

bool subsetSumZero(ll *arr,ll n,ll sum,ll k)
{
    if(n==0)
    {
        if(sum==0 && k!=0)
            return true;
        return false;
    }
    bool a=subsetSumZero(arr,n-1,sum,k);
    k++; //last element of arr passed to func is included
    bool b=subsetSumZero(arr,n-1,sum+arr[n-1],k);
    return a || b;
}

int main() {
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        ll n;
        cin>>n;
        ll *arr=new ll [n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll sum=0,k=0;
        bool ans=subsetSumZero(arr,n,sum,k);
        if(ans)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}