#include <iostream>
using namespace std;

void uniqueNumbers(int* arr,int n)
{
    int res=0;  //xor value of 2 unique numbers
    for(int i=0;i<n;i++)
    {
        res=res^arr[i];
    }
    //finding the first set bit in res
    int i=0,temp=res;
    while(temp>0)
    {
        if(temp&1)  //finding the first set bit
            break;
        i++;
        temp=temp>>1;
    }
    //performing operation on all those numbers that have ith bit as set
    int p=1;
    for(int j=0;j<n;j++)
    {
        if(arr[j] & (1<<i))
            p=p^arr[j];
    }
    cout<<p<<" ";
    res=res^p;
    cout<<res;
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    uniqueNumbers(arr,n);
}
