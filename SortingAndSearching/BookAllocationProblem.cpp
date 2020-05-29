#include<iostream>
using namespace std;
#define ll long long 

bool isValid(ll *pages,ll n,ll m,ll mid)
{
    ll countOfStudents=1;
    ll currentPages=0;
    for(int i=0;i<n;i++)
    {
        //currentPages+=pages[i];
        if(currentPages+pages[i]>mid)
        {
            countOfStudents++;
            currentPages=pages[i];
            if(countOfStudents>m)
                return false;
        }
        else
        {
            currentPages+=pages[i];
        }
    }
    return true;
}

ll findMaxPages(ll *pages,ll n,ll m)
{
    ll s=pages[n-1];  //becoz each student has to read atleast max pages  //0;  // or pages[0]; //min no of pages 
    ll e=0;
    ll finalAns=0;
    for(ll i=0;i<n;i++)
    {
        e+=pages[i];  //e is the sum of all the pages
    }
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(isValid(pages,n,m,mid))
        {
            finalAns=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return finalAns;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ll n,m;
        cin>>n>>m;  //n books, m students
        ll *pages=new ll[n];
        for(ll i=0;i<n;i++)
        {
            cin>>pages[i];  //ascending order
        }
        ll ans=findMaxPages(pages,n,m);
        cout<<ans<<endl;
        delete [] pages;  //deleting dynamic array
        pages=0;          //pointing to null bcoz pointer in static memory not deleted
    }
	return 0;
}