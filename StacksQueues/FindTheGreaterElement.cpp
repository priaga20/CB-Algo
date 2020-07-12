#include <iostream>
#include<stack>
using namespace std;

void nextGreater(int *arr,int n)
{
    //duplicating the array to satisfy circular array property
    int *duplicate= new int [2*n];
    for(int i=0;i<2*n;i++)
    {
        duplicate[i]=arr[i%n];
    }

    stack<int> s;
    s.push(0);
    int *ans = new int[n];
    for(int i=1;i<2*n;i++)
    {
        if(s.empty() && i<n)
        {
            s.push(i);
            continue;
        }

        while(!s.empty() && duplicate[s.top()]<duplicate[i])
        {
            if(s.top()<n)
                ans[s.top()]=duplicate[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        if(s.top()<n)
            ans[s.top()]=-1;
        s.pop();
    }

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    nextGreater(arr,n);
    delete [] arr;
    arr=0;
    return 0;
}