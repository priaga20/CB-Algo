#include <iostream>
#include<set>
#include<string>
using namespace std;
set<string> s;

void permutations(string str,int i)   //i is starting index of str
{
    if(str[i]=='\0')
    {
        s.insert(str);
        return;
    }   
    for(int j=i;str[j]!='\0';j++)
    {
        swap(str[j],str[i]);
        permutations(str,i+1);
        //backtrack
        swap(str[j],str[i]);
    }
}

int main() {
    string str;
    cin>>str;
    permutations(str,0);
    for(auto i:s)
    {
        cout<<i<<endl;
    }
}