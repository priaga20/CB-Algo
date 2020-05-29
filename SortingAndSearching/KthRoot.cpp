#include <iostream>
#include<math.h>
using namespace std;
#define ll long long 

ll int findKthRoot(ll int n, int k)
{
    ll int s=1,e=n;
    ll int ans=0;
    while(s<=e)
    {
        ll int mid=(s+e)/2;
        if(pow(mid,k) == n)
        {
            ans=mid;
            break;
        }
        if(pow(mid,k)<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll int n;
        int k;  
        cin>>n>>k;
        cout<<findKthRoot(n,k)<<endl;
    }
}
