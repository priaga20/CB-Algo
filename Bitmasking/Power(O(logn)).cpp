#include<iostream>
using namespace std;

int fastExponentiation(int a,int b)
{
	int ans=1, x=a;
	while(b>0)
	{
		int last_bit=(b&1);
		if(last_bit==1)
			ans=ans*x;
		x=x*x;
        b=b>>1;
	}
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<fastExponentiation(a,b);
}