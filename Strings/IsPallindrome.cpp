#include<iostream>
using namespace std;

bool isPalindrome(int *arr,int start,int end)
{
    if(arr[start]!=arr[end])
        return false;
    if(start==end || start>end)
        return true;
    if(arr[start]==arr[end])
        isPalindrome(arr,start+1,end-1);
}

int main() {
	int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bool ans=isPalindrome(arr,0,n-1);
    if(ans)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}