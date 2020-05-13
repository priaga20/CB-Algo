#include <iostream>
using namespace std;

int multiply(int* res,int x,int size){
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int prod=res[i]*x + carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        res[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}

void factorial(int n)
{
    int res[10000];
    int size=1;
    res[0]=1;
    for(int i=2;i<=n;i++)   //1*2*3*4....*n
    {
        size=multiply(res,i,size);
    }

    //printing
    for(int i=size-1;i>=0;i--)
    {
        cout<<res[i];
    }
}

int main() {
    int n;
    cin>>n;
    factorial(n);
}
