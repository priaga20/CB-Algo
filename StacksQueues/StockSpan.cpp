#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	stack<int> s;
	//maintaining max element to left of curr element as top of stack
	for(int i=0;i<n;i++)
	{
		//if curr element is greater than top of stack i.e. now the curr element is max 
		while(!s.empty() && arr[i]>=arr[s.top()])
		{
			s.pop();
		}

		if(s.empty())  //means no element is greater than curr element to left of it
		{
			cout<<i+1<<" ";
			//pushing max element uptill now to stack
			s.push(i);
		}
		else
		{
			cout<<i-s.top()<<" ";
			s.push(i);
		}
	}
	

	cout<<"END";
	delete [] arr;
	arr=0;
}
