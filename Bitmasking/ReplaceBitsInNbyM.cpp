//given two 32 bit numbers, N amd M, and two bit positions i and j.
//write a method to set all bits between i and j in N equal to M. 
//M becomes a substring of N located at i and starting at j

#include <iostream>
using namespace std;

int clearBits(int n,int i,int j)
{
    int mask = (~(-1<<i)) | (-1<<(j+1));
    return (n&mask);
}

int replaceBits(int n,int m,int i,int j)
{
    //clear i to j bits in n
    n=clearBits(n,i,j);
    m= m<<i;
    return n|m;
}

int main() {
    int m,n,i,j;
    cin>>m>>n>>i>>j;
    cout<<replaceBits(n,m,i,j);
}
