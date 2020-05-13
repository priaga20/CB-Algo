#include<iostream>
using namespace std;

void sumArrays(int *a,int n,int *b,int m)
{
	int i=n-1,j=m-1;
	int c=0;
	int ans[m+n];
	int k=0;
	while(i>=0 && j>=0)
	{
		int s=a[i]+b[j]+c;
		ans[k]=s%10;
		c=s/10;
		k++;
		i--;
		j--;
	}
	while(j>=0)
	{
		int s=b[j]+c;
		ans[k]=s%10;
		c=s/10;
		k++;
		j--;
	}
	while(i>=0)
	{
		int s=a[i]+c;
		ans[k]=s%10;
		c=s/10;
		k++;
		i--;
	}
	if(c!=0)
	{
		ans[k]=c;
		k++;
	}
	for(int i=k-1;i>=0;i--)
	{
		cout<<ans[i]<<", ";
	}
	cout<<"END";
}

int main() {
	int n,m;
	int a[100],b[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	sumArrays(a,n,b,m);
	return 0;
}