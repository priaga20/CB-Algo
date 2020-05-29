#include <iostream>
#include<limits.h>
using namespace std;

void sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[minIndx]>arr[j])
            {
                minIndx=j;
            }
        }
        swap(arr[i],arr[minIndx]);
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
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    delete [] arr;
    arr=0;
    return 0;
}