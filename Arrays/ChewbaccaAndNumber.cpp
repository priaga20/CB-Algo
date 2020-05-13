#include <iostream>
using namespace std;
#define ll long long

ll func(ll x)
{
    if(x==0)
        return 0;
    int r=x%10;
    int smallAns=func(x/10);
    if(r==9 && x/10==0)  //9 is first digit
        r=9;
    else if(r>=5)
        r=9-r;
    return smallAns*10+r;
}

int main() {
    ll x;
    cin>>x;
    ll ans=func(x);
    cout<<ans;
    return 0;
}
