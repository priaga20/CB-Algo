#include <iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int lastOcc[256];
	for(int i=0;i<256;i++)
	{
		lastOcc[i]=-1;
	}

	int maxLen=0,startIndex=0;

	for(int i=0;i<s.size();i++)
	{
		if(lastOcc[s[i]]==-1)  //occuring for the first time
		{
			lastOcc[s[i]]=i;   //storing the index of its last occurence
			maxLen= max(maxLen,i-startIndex+1);
		}
		else
		{
			//check if s[i] is in current window or not 
			if(lastOcc[s[i]]>=startIndex && lastOcc[s[i]]<i)  //in current window
			{
				//updating new startIndex i.e. after the last occ of current char
				//shrink the window
				startIndex = lastOcc[s[i]]+1;
				lastOcc[s[i]]=i;
				maxLen = max(maxLen , i-startIndex+1);
			}
			else  //not in current window
			{
				lastOcc[s[i]]=i;   //storing the index of its last occurence
				maxLen= max(maxLen,i-startIndex+1);
			}
		}
	}
	cout<<maxLen;
}