#include <iostream>
using namespace std;

int calculateSum(int *coins,int n)
{
    if(n<=0)
        return 0;
    int sum=coins[n-1];
    return sum+calculateSum(coins,n-2);
}

int main() {
    int n;
    cin>>n;
    int *coins=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    int evenSum=calculateSum(coins,n);
    int oddSum=calculateSum(coins,n-1);
    int ans=max(evenSum,oddSum);
    cout<<ans;
    return 0;
}
