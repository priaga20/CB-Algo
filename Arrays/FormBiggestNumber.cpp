#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool myCompare(string X,string Y)
{
	string XY=X.append(Y);
	string YX=Y.append(X);
	return XY>YX;
}

void formBiggestNumber(vector<string>a,int n)
{
	sort(a.begin(),a.end(),myCompare);
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector <string> a;
		for(int j=0;j<n;j++)
		{
			string p;
			cin>>p;
			a.push_back(p);
		}
		formBiggestNumber(a,n);
		cout<<endl;
	}
	return 0;
}
