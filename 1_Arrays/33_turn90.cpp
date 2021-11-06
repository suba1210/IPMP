#include<bits/stdc++.h>
using namespace std;

int main()
{
    int image[][4] = {{1,2,3,4}, 
                      {5,6,7,8},
                      {9,10,11,12}}; 

    int r=3,c=4,i,j;
    int dest[c][r];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            dest[j][r-i-1]=image[i][j];
        }
    }

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            cout<<dest[i][j]<<" ";
        }
        cout<<'\n';
    }
    
}