#include <iostream>
#include<stack>
using namespace std;

class queue{
	stack<int> s1;
	stack<int> s2;
	int cs;
	int ms;

public:
	queue(int ds)   //default size
	{
		cs=0;
		ms=ds; 
	}

	void enqueue(int n)
	{
		s1.push(n);
	}

	bool isEmpty()
	{
		return cs==0;
	}

	void dequeue(){
		if(s1.empty())
			return;
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return;
	}

	int getFront()
	{
		if(s1.empty())
			return -1;
		int top;
		while(!s1.empty())
		{
			top=s1.top();
			s2.push(top);
			s1.pop();
		}
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return top;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	queue q(n);
	for(int i=0;i<n;i++)
	{
		q.enqueue(i);
	}
	for(int i=0;i<n;i++)
	{
		cout<<q.getFront()<<" ";
		q.dequeue();
	}
	return 0;
}