#include<iostream>
#include<string>
#include<vector>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn [] = { "prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku" };

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

	for(int i=0;i<output.size();i++)
    {
        for(int j=0;j<11;j++)
        {
        	//The function returns the index of the first occurrence of sub-string, 
        	//if the sub-string is not found it returns string::npos(string::pos is static 
        	//member with value as the highest possible for the size_t data structure).
            if(searchIn[j].find(output[i])<searchIn[j].size())    
            {
                cout<<searchIn[j]<<endl;
            }
        }
    }

	return 0;
}