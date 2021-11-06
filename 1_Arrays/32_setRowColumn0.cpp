#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int> > matrix;

    matrix = {{1,1,1},{1,0,1},{1,1,1}};
    int r=3,c=3,i,j;
    bool zeroCol = false;

    for(i=0;i<r;i++)
    {
        if(matrix[i][0] == 0)
        {
            zeroCol = true;
        }

        for(j=1;j<c;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(!matrix[i][0] || !matrix[0][j])
            {
                matrix[i][j]=0;
            }
        }
    }

    if(matrix[0][0]==0)
    {
        for(i=0;i<c;i++)
        {
            matrix[0][i]=0;
        }
    }

    if(zeroCol)
        for(i=0;i<r;i++)
            matrix[i][0]=0;   


    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<'\n';
    }

}

/* APPROACH :

class Solution {
  public void setZeroes(int[][] matrix) {
    Boolean isCol = false;
    int R = matrix.length;
    int C = matrix[0].length;

    for (int i = 0; i < R; i++) {

      // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // For this solution we are using an additional variable for the first column
      // and using matrix[0][0] for the first row.
      if (matrix[i][0] == 0) {
        isCol = true;
      }

      for (int j = 1; j < C; j++) { // HERE ITERATION OCCURS ONLY AT THE INNER MATRIX
        // If an element is zero, we set the first element of the corresponding row and column to 0
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    // Iterate over the array once again and using the first row and first column, update the elements.
    for (int i = 1; i < R; i++) {
      for (int j = 1; j < C; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // See if the first row needs to be set to zero as well
    if (matrix[0][0] == 0) {
      for (int j = 0; j < C; j++) {
        matrix[0][j] = 0;
      }
    }

    // See if the first column needs to be set to zero as well
    if (isCol) {
      for (int i = 0; i < R; i++) {
        matrix[i][0] = 0;
      }
    }
  }
}

*/