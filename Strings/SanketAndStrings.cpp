#include <iostream>
#include<string>
using namespace std;

int maxLen(string s,int k)
{
    int l=0,r=0,temp=k,n=s.size(),len=0;
    while(l<n && r<n)
    {
        while(r<n && s[l]==s[r]){
            r++;
        }
        while(r<n && s[l]!=s[r] && k>0){
            k--;
            r++;
        }
        if(r==n){
            len=max(len,r-l);
            break;
        }
        if(k==0){
            if(s[l]==s[r])   //more chars can be included
                continue;
            else
                len=max(len,r-l);    //r excluded
            k=temp;
            l++;
            r=l;
        }
    }
    return len;
}

int main() {
    int k;
    cin>>k;
    string s;
    cin>>s;
    cout<<maxLen(s,k);
    return 0;
}
