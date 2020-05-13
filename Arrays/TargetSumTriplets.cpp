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

    for(int i=0;i<n;i++)
    {
        int l=i+1,r=n-1;
        while(l<r)
        {
            if(a[l]+a[r]+a[i]==target)
            {
                cout<<a[i]<<", "<<a[l]<<" and "<<a[r]<<endl;
                l++;
                r--;
            }
            else if(a[l]+a[r]+a[i]>target)
                r--;
            else
                l++;
        }
    }
    delete [] a;
    a=0;
	return 0;
}