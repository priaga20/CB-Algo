#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int target;
    cin>>target;

    sort(a,a+n);

    int l=0;
    int r=n-1;
    while(l<r)
    {
        if(a[l]+a[r]==target)
        {
            cout<<a[l]<<" and "<<a[r]<<endl;
            l++;
            r--;
        }
        else if(a[l]+a[r]>target)
        {
            r--;
        }
        else{
            l++;
        }
    }
    delete [] a;
    a=0;
	return 0;
}