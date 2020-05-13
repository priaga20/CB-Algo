#include <iostream>
using namespace std;

void rotateImage(int** &arr,int n)
{
    //reversing each row
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(arr[i][j],arr[i][n-j-1]);
        } 
    }
    //taking transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int **arr=new int * [n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    rotateImage(arr,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}