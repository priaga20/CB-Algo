#include<iostream>
#include<vector>
using namespace std;
#define s 1000000


vector<int> primeSeive()
{
	vector<int> seive;
	seive.resize(s);
	seive[2]=1;
	for(int i=3;i<s;i+=2)
	{
		seive[i]=1;
	}
	for(int i=3;i*i<s;i+=2)
	{
		if(seive[i])
		{
			for(int j=i*i;j<s;j+=i)
			{
				seive[j]=0;
			}
		}
	}
	vector<int> primes;
	primes.push_back(2);
	for(int i=3;i<s;i+=2)
	{
		if(seive[i])
		{
			primes.push_back(i);
		}
	}
	return primes;
}

int main() {
	vector<int> p=primeSeive();
	int n;
	cin>>n;
	cout<<p[n-1];
	return 0;
}