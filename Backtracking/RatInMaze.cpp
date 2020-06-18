#include <iostream>
using namespace std;

bool ratInMaze(char **maze, int **soln, int n, int m, int i, int j)
{
    //reached destination
    if(i==n && j==m)
    {
        soln[i][j]=1;
        //print path
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    //out of grid check
    if(i>n || j>m)
        return false;

    //cell is blocked check
    if(maze[i][j]=='X')
        return false;

    //assuming current cell is in path
    soln[i][j]=1;

    //rat tries to go right from curr position
    bool rightSuccess= ratInMaze(maze,soln,n,m,i,j+1);
    if(rightSuccess)
        return true; //have to find rightmost path so if rightSuccess is true then no need to check down

    bool downSuccess= ratInMaze(maze,soln,n,m,i+1,j);
    if(downSuccess)
        return true;

    //backtrack bcoz if reached here then curr cell is not a part of path
    soln[i][j]=0;
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;
    char **maze=new char*[n]; //n rows
    int **soln=new int*[n];
    for(int i=0;i<n;i++)
    {
        maze[i]=new char[m];
        soln[i]=new int[m]();  //initialising with 0
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
        }
    }
    bool ans=ratInMaze(maze,soln,n-1,m-1,0,0);
    if(!ans)
    {
        cout<<"-1";
    }
    delete [] maze;
    maze=0;
}
