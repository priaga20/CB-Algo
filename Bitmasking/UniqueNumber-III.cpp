#include <iostream>
using namespace std;

void uniqueNumbers(int *arr, int n)
{
    int count[64]={0};
    for(int i=0;i<n;i++)
    {
        int t=arr[i],p=0;
        while(t>0)
        {
            if(t&1 )  
            {
                count[p]++;
            }
            p++;
            t=t>>1;
        }
    }
    int ans=0,p=1;
    for(int i=0;i<64;i++)
    {
        count[i] %=3;
        ans+= (count[i]*p);
        p=p<<1;
    }
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    uniqueNumbers(arr,n);
}
