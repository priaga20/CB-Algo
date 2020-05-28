#include<iostream>
#include<string>
using namespace std;

char maxFrequency(string s)
{
    int *freq=new int[26]();
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]-'a']++;
    }
    int max=0;
    char c;
    for(int i=0;i<26;i++)
    {
        if(freq[i]>max)
        {
            max=freq[i];
            c='a'+i;
        }    
    }
    return c;
}

int main() {
    string s;
    cin>>s;
    cout<<maxFrequency(s);
	return 0;
}