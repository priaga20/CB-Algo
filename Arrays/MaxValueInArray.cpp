#include<iostream>
#include<climits>
using namespace std;

int main() {
	int n;
	cin>>n;
	int* arr=new int[n];
	int maxEle=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>maxEle)
			maxEle=arr[i];
	}
	cout<<maxEle;
	delete [] arr;
	arr=0;
	return 0;
}