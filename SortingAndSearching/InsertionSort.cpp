#include <iostream>
using namespace std;

void sort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int val=arr[i];
        int hole=i;
        while(hole>0 && val<arr[hole-1])
        {
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=val;
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