#include<iostream>
#include<string>
using namespace std;

void generateBrackets(int n,string output,int open,int close)
{
	if(output.size()==2*n)
		cout<<output;

	if(open < n)
		generateBrackets(n,output+"(",open+1,close);

	if(close<open)
		generateBrackets(n,output+")",open,close+1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	string output="";
	generateBrackets(n,output,0,0);

	return 0;
}