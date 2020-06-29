#include <iostream>
using namespace std;

int dx[]= {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[]= {-1, 1, -2, 2, -2, 2, -1, 1};

int chessBoard(int board[10][10],int visited[10][10],int i,int j,int n)
{
    int maxFilledCells=0;
    //out of board check
    if(i<0 || j<0 || i>=n || j>=n)
        return 0;

    //cell not a part of funky chess board
    if(board[i][j]==0)
        return 0;

    //if cell is already visited
    if(visited[i][j])
        return 0;

    //rec case
    visited[i][j]=1;
    for(int k=0;k<8;k++)
    {
        int filled= 1+chessBoard(board,visited,i+dx[k],j+dy[k],n);
        maxFilledCells= max( maxFilledCells, filled);
    }
    //backtrack
    visited[i][j]=0;
    return maxFilledCells;
}

int main() {
    int n;
    cin>>n;
    int board[10][10];
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
            if(board[i][j]==1)
                c++;
        }
    }
    int visited[10][10]={0};
    cout<<c-chessBoard(board,visited,0,0,n);
}