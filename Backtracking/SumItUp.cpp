#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

set<vector<int>> v;

//t is target
//s is starting index of remaining array
bool sumItUp(int *arr,int n,int t,int s,int* &visited)
{
    //base case
    if(t==0)
    {
        vector<int> v1;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                v1.push_back(arr[i]);
        }
        v.insert(v1);
        //return true;
        return false;
    }
    for(int i=s;i<n;i++)
    {
        
        if(arr[i]<=t)
        {
            
            visited[i]=1;
            
            bool ans=sumItUp(arr,n,t-arr[i],i+1,visited);
            if(ans)
                return true;
            visited[i]=0;  //backtrack
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int t;
    cin>>t;

    sort(arr,arr+n);
    int *visited=new int[n]();
    sumItUp(arr,n,t,0,visited);

    for(auto i:v)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}