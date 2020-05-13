#include<iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int a[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int c=0;c<m;c++)
    {
        for(int r=0;r<n;r++)
        {
            if(c%2==0)
            	cout<<a[r][c]<<", ";
            else
            	cout<<a[n-r-1][c]<<", ";
        }
    }
    cout<<"END";
	return 0;
}