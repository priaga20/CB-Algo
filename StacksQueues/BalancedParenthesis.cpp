#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    string exp;
    cin>>exp;

    stack<char> s;
    int flag=0;

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
        {
            s.push(exp[i]);
            continue;
        }

        if(s.empty())
        {
            cout<<"No";
        }
        else if(exp[i]=='}' || exp[i]==')' || exp[i]==']')
        {
            char temp=s.top();
            s.pop();
            if(exp[i]==')' && temp=='(')
            {
               continue;
            }
            else if(exp[i]=='}' && temp=='{')
            {
               continue;
            }
            else if(exp[i]==']' && temp=='[')
            {
               continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
    }
    if(s.empty() && flag==0)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}