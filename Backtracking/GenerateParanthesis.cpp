#include <iostream>
#include<string>
using namespace std;

void generateParenthesis(int n, int open, int close, string curr)
{
	if(open+close == 2*n){
		cout<<curr<<endl;
		return;
	}

	
	if(close<open)
		generateParenthesis(n,open,close+1,curr+")");
	if(open<n)
		generateParenthesis(n,open+1,close,curr+"(");

	
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	string curr = "";
	generateParenthesis(n,0,0,curr);
	return 0;
}