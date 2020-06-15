#include<iostream>
using namespace std;

int maxProfit(int n, int c, int *wts, int* profit)
{
	if(n==0 || c==0)
		return 0;

	//not including last item
	int op1 = maxProfit(n-1, c, wts, profit);

	//including last item
	int op2=0;
	if(wts[n-1]<=c)
		op2 = profit[n-1]+maxProfit(n-1, c-wts[n-1], wts, profit);

	return max(op1,op2);
}

int main(int argc, char const *argv[])
{
	int n,c;   //no of items and capacity
	cin>>n>>c;

	int* wts= new int[n];
	int  *profit= new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>wts[i];
	}

	for(int i=0;i<n;i++)
	{
		cin>>profit[i];
	}

	cout<<maxProfit(n,c,wts,profit);

	return 0;
}