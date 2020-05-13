#include<iostream>
using namespace std;

void findTarget(int n,int m,int a[100][100],int t)
{
	int i=0,j=m-1,flag=0;
	while(j>=0 && i<n)
	{
		if(a[i][j]<t)
		{
			i++;
		}
		else if(a[i][j]>t)
		{
			j--;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag)
		cout<<"1";
	else 
		cout<<"0";
}

int main() {
	int n,m;
	cin>>n>>m;
	int a[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int t;
	cin>>t;
	findTarget(n,m,a,t);
	return 0;
}