#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10], int n, int m, int i, int j)
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
    if(i>n || j>m || i<0 || j<0)
        return false;

    //cell is blocked check
    if(maze[i][j]=='X')
        return false;

    //cell is already visited
    //imp to check otherwise will go in infinite loop
    if(soln[i][j]==1)
        return false;

    //assuming current cell is in path
    soln[i][j]=1;

    //rat tries to go in all 4 directions from curr position
    bool rightSuccess, downSuccess, leftSuccess, upSuccess;

    leftSuccess= ratInMaze(maze,soln,n,m,i,j-1);
    rightSuccess= ratInMaze(maze,soln,n,m,i,j+1);
    upSuccess= ratInMaze(maze,soln,n,m,i-1,j);
    downSuccess= ratInMaze(maze,soln,n,m,i+1,j);

    if(rightSuccess || downSuccess || leftSuccess || upSuccess)
        return true; 

    //backtrack bcoz if reached here then curr cell is not a part of path
    soln[i][j]=0;
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;
    
    char maze[10][10];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    
    int soln[10][10]={0};
    
    bool ans = ratInMaze(maze,soln,n-1,m-1,0,0);
    
    if(ans==false){
        cout<<"NO PATH FOUND";
    }
    
    return 0;
}


