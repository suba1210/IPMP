#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 6

void spiralPrint(int m , int n, int a[][C])
{
    int i,row=0,col=0;
    int last_row = m-1, last_col = n-1;
    while(row<=last_row && col<=last_col)
    {
        for(i=col;i<=last_col;i++)
        {
            cout<<a[row][i]<<" ";
        }
        row++;

        for(i=row;i<=last_row;i++)
        {
            cout<<a[i][last_col]<<" ";
        }
        last_col--;

        if(row<=last_row)
        {
            for(i=last_col;i>=col;i--)
            {
                cout<<a[last_row][i]<<" ";
            }
        }
        last_row--;

        if(col<=last_col)
        {
            for(i=last_row;i>=row;i--)
            {
                cout<<a[i][col]<<" ";
            }
        }
        col++;
    }
}


int main()
{
    int a[R][C] = { { 1, 2, 3, 4, 5, 6 },
                    { 7, 8, 9, 10, 11, 12 },
                    { 13, 14, 15, 16, 17, 18 } };
 
    spiralPrint(R, C, a);
    return 0;
}
