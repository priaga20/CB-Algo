#include <iostream>
#include<string>
#include<set>
using namespace std;

set<string> s;

void dictionary(string str,int i)
{
    //base case
    if(str[i]=='\0')
        s.insert(str);

    //rec case
    for(int j=i;j<str.size();j++)
    {
        swap(str[i],str[j]);
        dictionary(str,i+1);
        //backtracking
        swap(str[i],str[j]);
    }
}

int main() {
    string str;
    cin>>str;

    dictionary(str,0);

    set<string> :: iterator it=s.find(str);
    it++; //bcoz not to print str itself
    for( ;it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}