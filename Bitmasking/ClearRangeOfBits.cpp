#include<iostream>
using namespace std;

void clearBits(int &n, int i,int j)
{
	int mask1= (-1 << (j+1));
	int mask2= ~(-1 << i);
	int mask= mask1 | mask2;
	n=n&mask;
}

int main()
{
	int n,i,j;
	cin>>n>>i>>j;   // i is lower index and j is higher index
	clearBits(n,i,j);
	cout<<n;
}