#include <iostream>
#include<vector>
#include<utility>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

bool myCompare(const pair<string,int> &a,const pair<string,int> &b)
{
    if(a.second==b.second)  //salaries equal
    {
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main() {
    int x;
    cin>>x;
    int n;
    cin>>n;
    vector<pair<string,int>> v;
    for(int i=0;i<n;i++)
    {
        string s;
        int sal;
        cin>>s>>sal;
        if(sal>=x)
        {
            pair<string,int> y=make_pair(s,sal);
            v.push_back(y);
        }
    }
    sort(v.begin(),v.end(),myCompare);
    for(auto const &y : v)
    {
        cout<<y.first<<" "<<y.second<<endl;
    }
}