#include <iostream>
using namespace std;
#define ll long long 

ll int divisibleSubArrays(ll int *arr,ll int n)
{
    //finding cumulative sum and taking mod simultaneously bcoz values are large 
    ll int *cm=new ll int[n+1];  
    cm[0]=0;
    for(ll int i=1;i<n+1;i++)
    {
        cm[i]=( (cm[i-1]%n) + (arr[i-1]%n) )%n;
        cm[i]=( cm[i] + n)%n; //to deal with negative modulo case
    }

    ll int *freq=new ll int[n] (); 
    //can have atmax n unique values bcoz mod of some value with n can give at max n unique values
    for(ll int i=0;i<n+1;i++)
    {
        freq[cm[i]]++;
    }

    ll int ans=0;
    for(ll int i=0;i<n;i++)
    {
        ll int m=freq[i];
        ans+=(m*(m-1))/2;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        ll int *arr=new ll int[n];
        for(ll int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll int ans=divisibleSubArrays(arr,n);
        cout<<ans<<endl;
        delete [] arr;
        arr=0;
    }
    
}
