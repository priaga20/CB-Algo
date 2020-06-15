#include <iostream>
#include<string>
using namespace std;

void replaceAllpi(string &s,int i)
{
	if(s[i+1]=='\0')
		return;
	if(s[i]=='p' && s[i+1]=='i'){
		s= s.substr(0,i)+"3.14"+s.substr(i+2);
		i+=3;
	}
	
	replaceAllpi(s,i+1);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;

	replaceAllpi(s,0);

	cout<<s<<endl;
	}
	return 0;
}