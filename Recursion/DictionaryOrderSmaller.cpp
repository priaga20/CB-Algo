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
    set<string> :: iterator it1=s.begin();
    
    for( ;it1!=it;it1++)
    {
        cout<<*it1<<endl;
    }
}