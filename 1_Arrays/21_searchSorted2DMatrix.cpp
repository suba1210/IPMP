/*
Aproach 1 : brute force


Approach 2:

The given number is greater than the current number: 
This will ensure that all the elements in the current row are smaller than the given number as the pointer is already at the 
right-most elements and the row is sorted. Thus, the entire row gets eliminated and 
continues the search for the next row. Here, elimination means that a row needs 
not be searched.

The given number is smaller than the current number: 
This will ensure that all the elements in the current column are greater than the given number.
Thus, the entire column gets eliminated and continues the search for the previous column, 
i.e. the column on the immediate left.

The given number is equal to the current number: 
This will end the search.

*/

#include<bits/stdc++.h>
using namespace std;


int search(int mat[][4],int n,int x)
{
    if(n==0)
    {
        cout<<"Not found";
        return -1;
    }

    int smallest = mat[0][0], largest = mat[n-1][n-1];
    if((x<smallest)||(x>largest))
    {
        cout<<"Not found";
        return -1;       
    }

    int i=0,j=n-1;

    while(i<n && j>=0)
    {
        if(mat[i][j]==x)
        {
            cout<<"Found";
            return 1;
        }
        if(mat[i][j]>x)
        {
            j--;
        }
        else{
            i++;
        }
    }

    cout << "n Element not found";
    return 0;
}

int main()
{
    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    int x = 200;
    search(mat, 4, x);
 
    return 0;    
}