#include<iostream>
using namespace std;

void printSpiral(int a[10][10],int r,int c)
{
    int sr=0,er=r-1,sc=0,ec=c-1;
    int cnt=0,total=r*c;
    while(sc<=ec && sr<=er)
    {
        if(cnt==total)
            break;
        for(int i=sr;i<=er;i++)
        {
            cout<<a[i][sc]<<", "; 
            cnt++;
        }
        sc++;
        if(cnt==total)
            break;
        for(int i=sc;i<=ec;i++)
        {
            cout<<a[er][i]<<", ";
            cnt++;
        }
        er--;
        if(cnt==total)
            break;
        //while doing er-- possibility is there that er becomes equal to sr
        //so to avoid printing of sr 2 times put this check below
        if(sr<er)
        {
            for(int i=er;i>=sr;i--)
            {
                cout<<a[i][ec]<<", ";
                cnt++;
            }
            ec--;
        }
        if(cnt==total)
            break;
        //while doing ec-- possibility is there that ec becomes equal to sc
        //so to avoid printing of sc 2 times put this check below
        if(sc<ec)
        {
            for(int i=ec;i>=sc;i--)
            {
                cout<<a[sr][i]<<", ";
                cnt++;
            }
            sr++;
        }
        
    }
    cout<<"END";
}



int main() {
	int r,c;
    cin>>r>>c;
    int a[10][10];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    printSpiral(a,r,c);
    return 0;
}

