#include <iostream>
using namespace std;

int dx[]= {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[]= {-1, 1, -2, 2, -2, 2, -1, 1};

void print(int board[10][10],int visited[10][10],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] && visited[i][j]==0)
                c++;
        }
    }
    cout<<c;
}

void chessBoard(int board[10][10],int visited[10][10],int i,int j,int n)
{
    //out of board check
    if(i<0 || j<0 || i>=n || j>=n)
        return;

    //cell not a part of funky chess board
    if(board[i][j]==0)
        return;
    //if cell is already visited
    if(visited[i][j])
        return;

    //rec case
    visited[i][j]=1;
    for(int k=0;k<8;k++)
    {
        chessBoard(board,visited,i+dx[k],j+dy[k],n);
    }
}

int main() {
    int n;
    cin>>n;
    int board[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }
    int visited[10][10]={0};
    chessBoard(board,visited,0,0,n);
    print(board,visited,n);
}