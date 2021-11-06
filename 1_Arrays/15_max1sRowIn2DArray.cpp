#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int rowWithMax1s(bool mat[][C])
{
    int i,j;
    int countRow=0;
    for(i=C-1;i>=0;i--)
    {
        if(mat[0][i]==1)
            countRow++;
    }

    int maxi = countRow;

    for(i=1;i<R;i++)
    {
        if(maxi==C)
            return C;
        else if(mat[i][C-1-maxi]==1)
        {
            for(j=(C-1-maxi);j>=0;j--)
            {
                if(mat[i][j]==1)
                    maxi++;
                else
                    break;
            }
        }
    }

    return maxi;
}

int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
 
    return 0;
}