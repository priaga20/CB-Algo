#include <iostream>
#include<queue>
#include<deque>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	queue<int> idealOrder;
	deque<int> callOrder;

	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		callOrder.push_back(v);
	}
	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		idealOrder.push(v);
	}

	int time=0;

	while(!callOrder.empty())
	{
		if(callOrder.front()==idealOrder.front())
		{
			time+=1;
			callOrder.pop_front();
			idealOrder.pop();
		}
		else
		{
			while(callOrder.front()!=idealOrder.front())
			{
				callOrder.push_back(callOrder.front());
				callOrder.pop_front();
				time+=1;
			}
		}
	}

	cout<<time;


	return 0;
}