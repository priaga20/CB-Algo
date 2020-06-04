#include <iostream>
using namespace std;

int xorProfit(int x,int y)
{
    int ans=0;
    for(int i=x;i<=y;i++)
    {
        for(int j=x;j<=y;j++)
        {
            ans=max(ans,i^j);
        }
    }
    return ans;
}

int main() {
    int x,y;
    cin>>x>>y;
    cout<<xorProfit(x,y);
}
