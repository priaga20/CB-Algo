#include<iostream>
using namespace std;

void generateSubsets(char* arr, int n)
{
	for(int i=0;i<(1<<n);i++)     //2^n -1 subsets 
	{
		int j=0;      //to access any particular index of char array 
        int t=i;      //can't modify i in further code , so a new var t is used 
		while(t>0)
		{
			int last_bit = t&1;
			if(last_bit)
				cout<<arr[j];
			j++;
			t=t>>1;
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	char *arr=new char[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	generateSubsets(arr,n);
}