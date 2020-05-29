#include<iostream>
#include<algorithm>
using namespace std;

bool isValid(int *stalls,int n,int c,int mid)
{
    int cowsPlaced=1;
    int lastPlacedCowIndx=0;
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-stalls[lastPlacedCowIndx]>=mid)
        {
            cowsPlaced++;
            lastPlacedCowIndx=i;
            if(cowsPlaced==c)
                return true;
        }
    }
    return false;
}

int findDist(int *stalls,int n,int c)
{
    sort(stalls,stalls+n);
    //monotonic search space on min dist
    int s=0,e=stalls[n-1]-stalls[0];
    int ans=0;
    while(s<=e)
    {
        int mid= (s+e)/2;
        if(isValid(stalls,n,c,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}

int main() {
    int n,c;
    cin>>n>>c;
    int *stalls=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>stalls[i];
    }
    int ans=findDist(stalls,n,c);
    cout<<ans;
    delete [] stalls;
    stalls=0;
	return 0;
}