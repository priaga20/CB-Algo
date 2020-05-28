#include<iostream>
#include<string>
using namespace std;

void CamelCase(string s)
{
    int start,end,i=0;
    while(i<s.size())
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            start=i;
            i++;
        }
        while(s[i]>='a' && s[i]<='z')
        {
            i++;
        }
        end=i-1;
		cout<<s.substr(start,end-start+1)<<endl;
        start=i;
    }
}

int main() {
    string s;
    cin>>s;
    CamelCase(s);
	return 0;
}