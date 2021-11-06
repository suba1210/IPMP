#include<bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 4


void diagonalMat(int mat[ROW][COL])
{
    int i,j,k;

    for(k=0;k<ROW;k++)
    {
        i=k;
        j=0;
        while(i>=0 && j<COL)
        {
            cout<<mat[i][j]<<" ";
            i-=1;
            j+=1;
        }
        cout<<'\n';
    }

    for(k=1;k<COL;k++)
    {
        i=ROW-1;
        j=k;

        while( i>=0 && j<COL)
        {
            cout<<mat[i][j]<<" ";
            i-=1;
            j+=1;
        }
        cout<<'\n';

    }
}

int main()
{
    int mat[ROW][COL] = { { 1, 2, 3, 4 },
                        { 5, 6, 7, 8 },
                        { 9, 10, 11, 12 },
                        { 13, 14, 15, 16 },
                        { 17, 18, 19, 20 }};

    diagonalMat(mat);
}