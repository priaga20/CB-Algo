#include <iostream>
using namespace std;
#define ll long long 
ll md= 1e9+7;

//using bottom up DP
ll int waysToTileFloorDP(int n,int m)
{
    ll int *dp=new ll int [n+1];
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        if(i<m)
            dp[i]=1;
        else if(i==m)
            dp[i]=2;
        else
            dp[i]=((dp[i-1]%md)+(dp[i-m]%md))%md;
    }

    return dp[n]%md;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<waysToTileFloorDP(n,m)<<endl;
    }
}

