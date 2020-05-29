#include <iostream>
using namespace std;
#define ll long long

int findNoOfStudents(ll n,ll m,ll x,ll y)
{
    ll s=0,e=n;
    ll ans=0;
    while(s<=e)
    {
        ll mid=s-(s-e)/2;
        //if coupons required to give discount to mid no of students are less than equal to available coupons
        //available coupons = coupons already present + coupons we get from n-mid students i.e. (n-mid)*y
        if(mid*x<=m+(n-mid)*y)
        {   ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

int main() {
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll ans=findNoOfStudents(n,m,x,y);
    cout<<ans;
}