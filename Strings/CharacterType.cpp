#include<iostream>
using namespace std;

int main() {
	char c;
	cin>>c;
	if(c>='A' && c<='Z')
		cout<<"U";
	else if(c>='a' && c<='z')
		cout<<"L";
	else
		cout<<"I";
	return 0;
}