#include <iostream>
#include<deque>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int *arr =new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;

	deque<int> q;  //will store indexes

	//processing first k elements
	for(int i=0;i<k;i++)
	{
		if(q.empty() || arr[q.back()]>arr[i])
			q.push_back(i);
		else
		{
			while(!q.empty() && arr[q.back()]<arr[i])
			{
				q.pop_back();
			}
			q.push_back(i);
		}
	}

	//processing rest of the elements
	for(int i=k;i<=n;i++)
	{
		int indx=q.front();
		cout<<arr[indx]<<" ";

		if(i==n)
			break;
		//out of window check
		if(indx <= i-k)
		{
			q.pop_front();
		}

		//next greater element check
		if(q.empty() || arr[q.back()]>arr[i])
			q.push_back(i);
		else
		{
			while(!q.empty() && arr[q.back()]<arr[i])
			{
				q.pop_back();
			}
			q.push_back(i);
		}
	}
	return 0; 
}