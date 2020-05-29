#include <iostream>
#include<algorithm>
using namespace std;

void sort(int *arr,int n)
{
    int max=*max_element(arr,arr+n);   
    int *freq=new int[max+1] ();  //() at the end is used to value-initialise the array elements to 0
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    //find cumulative sum
    for(int i=1;i<max+1;i++)
    {
        freq[i]=freq[i]+freq[i-1];
    }
    int *newArr=new int[n];
    for(int i=0;i<n;i++)
    {
        int indx=freq[arr[i]]-1;
        newArr[indx]=arr[i];
        freq[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<newArr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);
    delete [] arr;
    arr=0;
    return 0;
}