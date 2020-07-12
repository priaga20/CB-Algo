#include<iostream>
#include<stack>
using namespace std;

long long int histogramArea(long long int *arr,int n)
{
    stack<int> s;
    long long int maxArea=0,area=0;
    int i=0;
    //using while loop so that we can control when we move to next bar
    while(i<n)
    {
        if(s.empty() || arr[s.top()]<=arr[i])
        {
            s.push(i);
            //every bar is pushed to stack once
            i++;
        }
        else
        {
            int top=s.top();
            s.pop();
            //assuming current bar to be min bar 
            //right index is current value of i
            //left index is the new top of stack after popping current bar
            if(s.empty())
                area=arr[top]*i;
            else
                area=arr[top]*(i-s.top()-1);
            maxArea=max(maxArea,area);
        }
    }

    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(s.empty())
            area=arr[top]*i;
        else
            area=arr[top]*(i-s.top()-1);
        maxArea=max(maxArea,area);   
    }

    return maxArea;
}

int main()
{
    int n;
    cin>>n;
    long long int *arr= new long long int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<histogramArea(arr,n);
    delete [] arr;
    arr=0;
}

