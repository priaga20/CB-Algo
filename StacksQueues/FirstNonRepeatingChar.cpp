#include <iostream>
#include<queue>
using namespace std;

int main()
{
	queue<char> q;

	int freq[26]={0};
	char ch;
	cin>>ch;
	while(ch!='.')
	{
		freq[ch-'a']++;
		q.push(ch);
		while(!q.empty())
		{
			int indx= q.front()-'a';
			if(freq[indx]>1)
				q.pop();
			else
			{
				cout<<q.front<<endl;
				break;
			}
		}
		if(q.empty())
			cout<<-1<<endl;
		cin>>ch;
	}
	return 0;
}