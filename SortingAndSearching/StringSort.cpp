#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

bool checkPrefix(string a,string b)
{
    int len=min(a.size(),b.size());
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

bool compare(string a,string b)
{
    if(checkPrefix(a,b) || checkPrefix(b,a))
    {
        return a.length()>b.length();
    }
    else
    {
        //not a substring
        return a<b; //return sorted array in ascending order
    }
}

int main() {
    int n;
    cin>>n;
    string arr[1000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}