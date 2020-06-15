#include<iostream>
using namespace std;

void mappedStrings(char *in, char* out, int i, int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}

	if(in[i]-'0'==0)
		return;

	int firstDigit= in[i]-'0';
	out[j]= firstDigit+'A'-1;
	mappedStrings(in,out,i+1,j+1);

	if(in[i+1] != '\0')
	{
		int secondDigit= in[i+1]-'0';
		int no = firstDigit*10 + secondDigit;
		if(no<=26)
		{
			out[j]= no+'A'-1;
			mappedStrings(in,out,i+2,j+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	char n[1000001];
	cin>>n;

	char out[1000001];

	mappedStrings(n,out,0,0);

	return 0;
}