#include <iostream>
using namespace std;

void classAssign(int *arr,int n,int i,int &ans)
{
	if(i==n)
	{
		ans++;
		return;
	}
	if(i==0)
	{
		arr[i]=3;
		classAssign(arr,n,i+1,ans);
		arr[i]=4;
		classAssign(arr,n,i+1,ans);
	}
	if(arr[i-1]==3)
	{
		arr[i]=3;
		classAssign(arr,n,i+1,ans);
		arr[i]=4;
		classAssign(arr,n,i+1,ans);
	}
	else if(arr[i-1]==4)
	{
		arr[i]=3;
		classAssign(arr,n,i+1,ans);
	}
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int *arr=new int[n]();
		int ans=0;
		classAssign(arr,n,0,ans);
		cout<<"#"<<i+1<<" : "<<ans<<endl;
	}
}