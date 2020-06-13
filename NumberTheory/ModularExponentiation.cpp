#include <iostream>
using namespace std;
#define ll long long 

ll int fastPower(int a,int b,int c)
{
    if(b==0)
        return 1;
    ll int smallAns=fastPower(a,b/2,c);
    smallAns*=smallAns;
    if(b%2==0)
        return smallAns%c;
    else
        return (a*smallAns)%c;
}

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    ll int ans=fastPower(a,b,c);
    cout<<ans;
    return 0;
}