#include <iostream>
#include<string>
using namespace std;

int main() {
    string s,ns="";
    cin>>s;
    int n=s.size();
    int i=0;
    while(i<n)
    {
        ns+=s[i];
        int c=1;
        while(s[i]==s[i+1])
        {
            c++;
            i++;
        }
        ns+=to_string(c);
        i++;
    }
    cout<<ns;
}