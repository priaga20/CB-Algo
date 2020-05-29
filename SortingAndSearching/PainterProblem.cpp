#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long 

bool isValid(ll *lengths,ll n,ll k,ll mid)
{
    ll paintersUsed=1;   //k is no of pallers so count of how many pallers are working at present 
    ll currentLengthAssigned=0;
    for(ll i=0;i<n;i++)
    {
        if(currentLengthAssigned+lengths[i]>mid)
        {
            paintersUsed++;
            currentLengthAssigned=lengths[i];
            if(paintersUsed>k)
                return false;
        }
        else
            currentLengthAssigned+=lengths[i];
    }
    return true;
}

ll getMax(ll *lengths,ll n) 
{ 
    ll max = INT_MIN; 
    for (ll i = 0; i < n; i++) 
        if (lengths[i] > max) 
            max = lengths[i]; 
    return max; 
} 
  
// return the sum of the elements in the array 
ll getSum(ll *lengths,ll n) 
{ 
    ll total = 0; 
    for (ll i = 0; i < n; i++) 
        total += lengths[i]; 
    return total; 
} 

ll binaryFindLength(ll *lengths,ll n,ll k)
{
    ll s=getMax(lengths,n);  // min time needed to paint board of longest length 
    ll e=getSum(lengths,n);  // max time can be sum of all lengths      
    ll finalAns=0;
    //k painters can work simultaneously
    //so trying to find out the min length a painter must paint 
    //assuming time needed to paint unit length is 1
    while(s<=e)
    {
        ll mid= s-(s-e)/2;
        if(isValid(lengths,n,k,mid))
        {
            finalAns=mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
    return finalAns;
}

int main() {
    ll noOfBoards,noOfPallers,timeForOneUnit;
    cin>>noOfBoards>>noOfPallers>>timeForOneUnit;
    ll* lengths=new ll[noOfBoards];
    for(ll i=0;i<noOfBoards;i++)
    {
        cin>>lengths[i];
    }
     //you are not allowed to sort the array as a continuous segment is allotted to a painter.
    // sort(lengths,lengths+noOfBoards);
    ll ans=binaryFindLength(lengths,noOfBoards,noOfPallers);  
    //finalAns calculated assuming 1 unit time for unit length
    ll finalAns=(ans*timeForOneUnit)%10000003;
    cout<<finalAns;
    delete[] lengths;
    lengths=0;
    return 0;
}