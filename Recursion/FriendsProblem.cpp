#include<iostream>
using namespace std;

int getWays(int n)
{
	if(n==0 || n==1)
		return 1;

	//can go alone or with a friend
	return 1*getWays(n-1) + (n-1)*getWays(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;  //no of friends

	cout<<getWays(n);

	return 0;
}