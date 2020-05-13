#include<iostream>
using namespace std;

int waterSaved(int *heights,int n)
{
	int *leftMax=new int[n]();
	int *rightMax=new int[n]();

	leftMax[0]=heights[0];
	for(int i=1;i<n;i++)
	{
		leftMax[i]=max(leftMax[i-1],heights[i]);
	}

	rightMax[n-1]=heights[n-1];
	for(int i=n-2;i>=0;i--)
	{
		rightMax[i]=max(rightMax[i+1],heights[i]);
	}

	//water collected
	int water=0;
	for(int i=0;i<n;i++)
	{
		water+=min(leftMax[i],rightMax[i])-heights[i];
	}
	return water;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *heights=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>heights[i];
	}
	cout<<waterSaved(heights,n);
	delete [] heights;
	heights=0;
	return 0;
}