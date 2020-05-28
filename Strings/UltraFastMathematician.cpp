#include <iostream>
#include<string>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string a,b,c="";
        cin>>a>>b;
        int n=a.size();
        int j=0;
        while(j<n)
        {
            if(a[j]==b[j])
                c+=to_string(0);
            else
                c+=to_string(1);
            j++;
        }
        cout<<c<<endl;
    }
}