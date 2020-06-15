#include<iostream>
using namespace std;

int fastPower(int a,int b)
{
	if(b==0)
		return 1;

	int smallAns=fastPower(a,b/2);

	if(b&1)
		return smallAns*smallAns*a;
	else
		return smallAns*smallAns;
}

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;

	cout<<fastPower(a,b);
	return 0;
}