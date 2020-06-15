#include<iostream>
using namespace std;

int countBinaryStrings(int n)
{
	if(n==2)
		return 3;
	if(n==1)
		return 2;
	return countBinaryStrings(n-1)+countBinaryStrings(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<countBinaryStrings(n);
	return 0;
}