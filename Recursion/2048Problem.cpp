#include<iostream>
#include<string>
using namespace std;

string s[]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printInWords(int n)
{
	if(n==0)
		return;

	int last_digit = n%10;
	printInWords(n/10);

	cout<<s[last_digit]<<" ";
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	printInWords(n);
	return 0;
}