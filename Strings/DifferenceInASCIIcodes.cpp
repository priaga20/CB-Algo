#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin>>s;
    string ns="";
    for(int i=0;i<s.size()-1;i++)
    {
        int diff=s[i+1]-s[i];
        ns+=s[i];
        ns+=to_string(diff);
    }
    ns+=s[s.size()-1];
    cout<<ns;
	return 0;
}