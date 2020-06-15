#include<iostream>
#include<string>
#include<vector>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

vector<string> printCombinations(string s, int i)
{
	if(i==s.size())
	{
		vector<string> t;
		t.push_back("");
		return t;
	}

	vector<string> smallAns = printCombinations(s,i+1);
	int len = smallAns.size();
	string t= table[s[i]-'0'];

	vector<string> output;
	for(int j=0;j<t.size();j++)
	{
		for(int k=0;k<len;k++)
		{
			output.push_back(t[j]+smallAns[k]);
		}
	}
	return output;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	vector<string> output;
	output=printCombinations(s,0);

	for(auto a: output)
	{
		cout<<a<<endl;
	}

	return 0;
}