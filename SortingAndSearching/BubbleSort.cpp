#include <iostream>
using namespace std;

void sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=1;j<n-i;j++)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                flag=1;
            }
        }
        if(!flag)
            break;
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