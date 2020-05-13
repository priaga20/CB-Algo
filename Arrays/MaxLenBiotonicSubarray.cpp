#include<iostream>
using namespace std;

int maxLen(int *arr,int n)
{
    int start=0,nextStart=0,j=0;
    int len=1;
    while(j<n-1)
    {
        //looking for end of ascent
        while(j<n-1 && arr[j]<=arr[j+1])
        {
            j++;
        }
        //looking for end for descent
        while(j<n-1 && arr[j]>=arr[j+1])
        {
            if(j<n-1 && arr[j]>arr[j+1])
            {
                nextStart=j+1;
            }
            j++;
        }
        len=max(len,j-start+1);
        start=nextStart;
    }
    return len;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<maxLen(arr,n)<<endl;
	}
	return 0;
}