#include <iostream>
using namespace std;

bool canEscape(char arr[][100],int n,int m,int &k,int &s)
{
    int i=0,j=0;
    while(i<n)
    {
        while(j<m)
        {
            if(s<k)
                return false;
            if(arr[i][j]=='#')
            {
                j=0;
                break;
            }
            else if(arr[i][j]=='.')
            {
                if(j==m-1)
                    s-=2;
                else
                    s-=3;
                j++;
            }
            else
            {
                if(j==m-1)
                    s+=5;
                else
                    s+=4;
                j++;
            }
        }
        i++;
        j=0;
    }
    return true;
}

int main() {
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    char arr[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    bool ans=canEscape(arr,n,m,k,s);
    if(ans)
        cout<<"Yes"<<endl<<s;
    else
        cout<<"No";
}