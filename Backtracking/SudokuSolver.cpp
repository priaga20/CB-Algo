#include <iostream>
#include<math.h>
using namespace std;

bool canWePlace(int** sudoku,int n,int i,int j,int t)
{
    //row check
    for(int x=0;x<n;x++)
    {
        if(sudoku[i][x]==t)
            return false;
    }
    //column check
    for(int x=0;x<n;x++)
    {
        if(sudoku[x][j]==t)
            return false;
    }
    //grid check
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(sudoku[x][y]==t)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(int** sudoku,int n,int i,int j)
{
    //Base Case
    if(i==n)
    {
        //print sudoku
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    //row end reached
    if(j==n) 
        return sudokuSolver(sudoku,n,i+1,0);

    //skip pre-filled cells
    if(sudoku[i][j]!=0)
        return sudokuSolver(sudoku,n,i,j+1);

    //Recursive case
    //try to fill cell with all possible values
    for(int t=1;t<=n;t++)
    {
        if(canWePlace(sudoku,n,i,j,t))
        {
            //assume we can place t at sudoku[i][j]
            sudoku[i][j]=t;
            //try to solve remaining sudoku
            bool couldWeSolve=sudokuSolver(sudoku,n,i,j+1);
            if(couldWeSolve)
                return true;
        }
    }

    //backtrack here, if after trying all possible values 
    sudoku[i][j]=0;
    return false;
}

int main() {
    int n;
    cin>>n;
    int **sudoku=new int*[n];
    for(int i=0;i<n;i++)
    {
        sudoku[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    bool ans=sudokuSolver(sudoku,n,0,0);
    delete [] sudoku;
    sudoku=0;
}
