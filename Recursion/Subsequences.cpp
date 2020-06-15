#include <iostream>
#include<string>
#include<vector>
using namespace std;

void subsequences(string s, int i, vector<string> &output)
{
	if(s[i]=='\0')
	{
		output.push_back("");
		return;
	}

	subsequences(s,i+1,output);

	int len = output.size();
	for(int j=0;j<len;j++)
	{
		output.push_back(s[i]+output[j]);
	}
}

int main()
{
	string s;
	cin>>s;

	vector<string> output;
	subsequences(s,0,output);

	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<" ";
	}
	cout<<endl;
	cout<<output.size();
}